#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Program to convert sasfit plugin models to sasmodels template

The script will perform following:
1) Read in sasfit file header information
2) Generate sasmodels python file
3) Generate category hierarchy
4) Translates sasfit errors handling into parameter ranges

The script returns converted c file and python template file.
The template file should in principle be ready to use but
some additional information ,may need to be filled in
"""


__author__ = "Wojtek Potrzebowski"
__maintainer__ = "Wojtek Potrzebowski"
__email__ = "Wojciech.Potrzebowski@esss.se"

import optparse
from string import split
from BeautifulSoup import BeautifulSoup, Comment
from collections import OrderedDict
from re import search

#TODO: Fix form volume

def parse_header_file(model_name, header_filename):
    """
    Extracts model description and parameters from sasfit header file
    :param model_name: string with model name
    :param header_filename: name of the header file to parse
    :return:
    """
    def_lines = []
    collect_def_lines = False
    model_name = "ff_"+model_name
    parameters = OrderedDict()

    for line in open(header_filename).readlines():
        if "################ start "+model_name in line:
            collect_def_lines = True
        if "################ stop "+model_name in line:
            collect_def_lines = False
        if collect_def_lines:
            def_lines.append(line.strip("\n"))

    collect_html_lines = False
    parameters_html = []
    functions = []
    count = 0
    for def_line in def_lines:
        if "defgroup" in def_line:
            words = split(def_line)
            defgroup = words[2]
        #TODO: This requires more understanding
        if "ingroup" in def_line:
            words = split(def_line)
            ingroup = words[2]
        if "brief" in def_line:
            brief_desc = def_line.split("brief")[1]
            if "<" and ">" in brief_desc:
                brief_desc = brief_desc[3:-3]
        if "note" in def_line:
            note = def_line.split("note")[1]
        if "par Required parameters:" in def_line:
            collect_html_lines = True
            continue
        if collect_html_lines:
            parameters_html.append(def_line)
        if "/table" in def_line:
            collect_html_lines = False
        if " * \sa " in def_line:
            functions.append(def_lines[count+3].strip("\r"))
        count += 1

    #Removing quote signs that cause problems
    brief_desc = brief_desc.replace("\"","")
    bs = BeautifulSoup("".join(parameters_html))

    #TODO: Preserve original sasfit order

    for row in bs.findAll('tr'):
        aux = row.findAll('td')
        parameters[aux[0].string[3:]] = aux[1].string

    return defgroup, ingroup, brief_desc, note, functions, parameters

def extrat_volume_parameters(model_name, parameters, model_source_file):
    """
    Based on given model parameters the model source file is parsed and
    volume parameters are extracted
    :param model_name:
    :param model_source_file:
    :param parameters:
    :return:
    """
    def_lines = []
    collect_def_lines = False
    model_name = "ff_"+model_name
    volume_parameters = OrderedDict()

    source_lines = open(model_source_file).readlines()
    for index, line in enumerate(source_lines):
        if "sasfit_"+model_name+"_v" in line:
            collect_def_lines = True
        if collect_def_lines:
            def_lines.append(line.strip("\n"))
        if "reuturn"+model_name in line and "}" in source_lines[index+1]:
            collect_def_lines = False
    for param in parameters.keys():
        for def_line in def_lines:
            if param in def_line:
                volume_parameters[param] = parameters[param]
    return volume_parameters
def check_for_pameter_redefinition(parameters, model_source_file):
    """
    Checking if file has DEFINE statements other than related to parameters
    :param parameters:
    :param model_source_file:
    :return:
    """
    extra_define_lines =[]
    source_lines = open(model_source_file).readlines()
    for index, line in enumerate(source_lines):
        if "#define" in line:
            paramter = line.strip("\n").split(" ")[1].split("\t")[0]
            if paramter not in parameters and "param->p" not in line:
                extra_define_lines.append(line)
    extra_define_lines.append(line+"\n")
    return extra_define_lines

def generate_python_file(model_name, brief_desc, note,
                         parameters, volume_parameters,
                         output_c_filename, output_python_filename):
    """
    Python file header generator
    :param output_python_file:
    :return:
    """
    output_python_file = open(output_python_filename, 'w')
    header_lines = "r\"\"\"\n"

    header_lines += "This file has been automatically gereated by sasfit_plugin_convert\n"

    header_lines += "The model calculates an empirical functional form " \
                    "for SAS data characterized\n"
    header_lines += "by "+model_name+"\n\n"
    header_lines += "Definition:\n"
    header_lines += brief_desc+"\n"
    header_lines += note+"\n"
    header_lines += "-----------\n\n"

    header_lines += "References:\n"
    header_lines += "-----------\n\n"

    header_lines += "\"\"\"\n"

    header_lines += "from numpy import inf\n\n"

    header_lines += "name = \""+model_name+"\"\n"
    header_lines += "title = \" \"\n"
    header_lines += "description = \""+brief_desc+"\"\n"
    header_lines += "category = \" \"\n"

    output_python_file.writelines(header_lines)

    #Generating python parameter file
    #It looks from interface that first value is set to 10.0, 4th to 1.0
    #and the rest is 0.0 and apparently standard models takes no more than
    #10 pramateres
    parameters_values = [10.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

    output_python_lines = "#pylint: disable=bad-whitespace, line-too-long\n"
    output_python_lines += "parameters = [\n"
    index = 0
    for param in parameters.keys():
        #print "Param def", param, param_def
        if param in volume_parameters.keys():
            output_python_lines += " [ \""+param+"\", \t\"\", \t"\
                               +str(parameters_values[index])+", " \
                                "\t[-inf, inf], \t\"volume\", " \
                                "\t\""+parameters[param]+"\"],\n"
        else:
            output_python_lines += " [ \""+param+"\", \t\"\", \t"\
                               +str(parameters_values[index])+", " \
                                "\t[-inf, inf], \t\"\", " \
                                "\t\""+parameters[param]+"\"],\n"
        index+=1
    output_python_lines += "]\n"
    output_python_lines +=" #pylint: enable=bad-whitespace, line-too-long\n\n"

    #FIXME: It should refer to c_file not model name
    output_python_lines +="source = [ "
    output_python_lines += " \"" + output_c_filename + "\" ]\n\n"

    output_python_lines +="demo = dict(\n"
    for index, param in enumerate(parameters.keys()):
        output_python_lines += "\t"+param+" = " \
        +str(parameters_values[index])+",\n"
    output_python_lines +=")\n"
    output_python_file.writelines(output_python_lines)

def generate_c_file(model_name, parameters, volume_parameters, extra_define_lines,
                    output_c_filename):
    """
    Generates c file read by sasmodels
    :param output_c_file:
    :param model_name:
    :param defgroup:
    :param ingroup:
    :param brief_desc:
    :param note:
    :param functions:
    :param parameters_html:
    :return:
    """

    output_c_file = open(output_c_filename, "w")
    #DO regular expression and remove if it is in line
    c_intro_lines = "///////////////////////////////////////////////////\n"
    c_intro_lines += "//    This is automatically generated file       //\n"
    c_intro_lines += "//    by sasfit_convert.py                       //\n"
    c_intro_lines += "//    Some editting may still be required        //\n"
    c_intro_lines += "///////////////////////////////////////////////////\n\n"

    c_intro_lines += "#include <sasfit_common.h>\n"
    c_intro_lines += "#include <sasfit_"+model_name+".h>\n\n"
    output_c_file.writelines(c_intro_lines)

    output_c_file.writelines(extra_define_lines)

    Iq_lines = "double Iq( double q,"
    Fq_lines = "double Fq( double q,"
    Iqxy_lines = "double Iqxy( double qx, double qy,"
    fv_lines = "double form_volume( "
    # Replace string in line when need

    for index, param in enumerate(parameters.keys()[:-1]):
        Fq_lines += " double "+param+", "
        Iq_lines += " double "+param+", "
        Iqxy_lines += " double "+param+", "
    Fq_lines+=" double "+parameters.keys()[-1]+")"
    Iq_lines+=" double "+parameters.keys()[-1]+")"
    Iqxy_lines+=" double "+parameters.keys()[-1]+")"

    output_c_file.writelines(Fq_lines+";\n")
    output_c_file.writelines(Iq_lines+";\n")
    output_c_file.writelines(Iqxy_lines+";\n")

    #TODO: Instead of parameters there should be volume paremeters here
    try:
        for index, param in enumerate(volume_parameters.keys()[:-1]):
            fv_lines += " double "+param+", "
        fv_lines+=" double "+volume_parameters.keys()[-1]+")"

        output_c_file.writelines(fv_lines+";\n\n")
    except:
        pass
    Fq_lines+=" {\n"
    Fq_lines+="sasfit_param param;\n"

    for index, param in enumerate(parameters.keys()):
        Fq_lines+="param.p["+str(index)+"] = "+param+";\n"

    Fq_lines+="return sasfit_ff_"+model_name+"_f(q, &param);\n}\n\n"

    Iq_lines+=" {\n"
    Iq_lines+="sasfit_param param;\n"

    for index, param in enumerate(parameters.keys()):
        Iq_lines+="param.p["+str(index)+"] = "+param+";\n"

    Iq_lines+="return sasfit_ff_"+model_name+"(q, &param);\n}\n\n"

    try:
        fv_lines+=" {\n"
        fv_lines+="double q;\n"
        fv_lines+="sasfit_param param;\n"
        fv_lines+="int dist;\n"

        for index, param in enumerate(volume_parameters.keys()):
            fv_lines+="param.p["+str(index)+"] = "+param+";\n"

        fv_lines+="return sasfit_ff_"+model_name+"_v(q, &param, dist);\n}\n\n"
    except:
        pass

    Iqxy_lines+="{\n"
    Iqxy_lines+="\tdouble q = sqrt(qx*qx + qy*qy);\n"
    Iqxy_lines+="\treturn Iq( q,"
    for param in parameters.keys()[:-1]:
        Iqxy_lines+=" "+param+","
    Iqxy_lines+=" "+parameters.keys()[-1]+");\n"
    Iqxy_lines+="}\n\n"

    output_c_file.writelines(Fq_lines)
    output_c_file.writelines(Iq_lines)
    output_c_file.writelines(Iqxy_lines)
    output_c_file.writelines(fv_lines)

def convert_sasfit_plugin(model_name, defgroup, ingroup, brief_desc, note,
                          functions, parameters, volume_parameters,
                          extra_def_lines, output_c_file, output_python_file):
    """
    Main conversion function
    :param sasfit_file:
    :param output_c_file:
    :param output_python_file:
    :return:
    """
    generate_python_file(model_name, brief_desc, note,
                         parameters, volume_parameters,
                         output_c_file, output_python_file)

    generate_c_file(model_name, parameters, volume_parameters, extra_def_lines,
                    output_c_file)

if __name__=="__main__":
    doc = """
            Script to convert sasfit files to sasmodels
            Usage: python sasfit_convert.py --help
        """
    print doc
    usage = "usage: %prog [options] args"
    option_parser_class = optparse.OptionParser
    parser = option_parser_class( usage = usage, version='0.1' )

    parser.add_option("-f", "--sasfit_file", dest="sasfit_header",
                      help="SASFit plugin header file [OBLIGATORY]")
    parser.add_option("-s", "--sasfit_source_file", dest="sasfit_source",
                      help="SASFit plugin source file [OBLIGATORY]")
    parser.add_option("-m", "--model_name", dest="model_name",
                      help="Model name or 'all' [OBLIGATORY]")
    parser.add_option("-o", "--output_file", dest="output_file",
                      help="Output c file and python file name [NO EXTENSION]")
    options, args = parser.parse_args()

    output_c_file = options.output_file+".c"
    output_python_file = options.output_file+".py"
    model_name = options.model_name

    defgroup, ingroup, brief_desc, note, functions, parameters = \
        parse_header_file(options.model_name, options.sasfit_header)

    volume_parameters = extrat_volume_parameters(options.model_name, parameters,
                                          options.sasfit_source)
    print parameters

    extra_def_lines = check_for_pameter_redefinition(parameters,
                                                     options.sasfit_source)

    convert_sasfit_plugin(model_name, defgroup, ingroup, brief_desc, note,
                          functions, parameters, volume_parameters,
                          extra_def_lines, output_c_file, output_python_file)
    print functions