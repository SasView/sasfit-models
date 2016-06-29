#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Program to convert sasfit form factor files to sasmodel template

In principle the template should provide already working model
but in some cases some information may need to be filled in manually

The script will perform following:
1) Remove sasfit specific includes
2) Translate sasfit parameters to sasmodels parameter table
3) Convert sasfit function headers to Iq, Iqxy
4) Translates sasfit errors handling into parameter ranges

The script returns converted c file and python template file.
The template file should in principle be ready to use but
some additional information ,may need to be filled in
"""
#TODO: Get the default values for the model parameters
#TODO: Retrive parameter description automatically
#TODO: Add categroy as an input parameter?
#TODO: Units
#TODO: Don't read EMPTY parameter in
#TODO: Add support for FQ and volume

__author__ = "Wojtek Potrzebowski"
__maintainer__ = "Wojtek Potrzebowski"
__email__ = "Wojciech.Potrzebowski@esss.se"

import os
import optparse
from re import search
from string import replace
from string import capwords
from string import rstrip
from string import lstrip


exclude_list = ["#include", "param->p",
                "sasfit_get_param",
                "SASFIT_ASSERT_PTR", "SASFIT_CHECK_COND1",
                "SASFIT_CHECK_COND", "SASFIT_CHECK_SUB_ERR"]

#Data types and GSL functions will be replcaced here
substitution_dict = {"scalar":"double",
                     #"ETA":"sld",
                     "gsl_pow_2":"sas_pow_2",
                     "gsl_pow_3":"sas_pow_3",
                     "gsl_pow_4":"sas_pow_4",
                     "gsl_pow_5":"sas_pow_5",
                     "gsl_pow_6":"sas_pow_6",
                     "gsl_pow_7":"sas_pow_7",
                     "gsl_pow_8":"sas_pow_8",
                     "gsl_pow_9":"sas_pow_9",
                     "gsl_pow_int": "sas_pow_int",
                     "gsl_sf_bessel_J0":"sas_J0",
                     "gsl_sf_bessel_J1":"sas_J1",
                     "gsl_sf_bessel_JN":"sas_JN",
                     "gsl_sf_bessel_j1":"sph_j1",
                     "gsl_sf_gamma":"sas_gamma",
                     "gsl_sf_Si":"Si",
                     "gsl_sf_erf":"sas_erf"}

#Data types and GSL functions will be replcaced here
libinclude_dict = {"gsl_pow_2":["sas_pow.c"],
                    "gsl_pow_3":["sas_pow.c"],
                    "gsl_pow_4":["sas_pow.c"],
                    "gsl_pow_5":["sas_pow.c"],
                    "gsl_pow_6":["sas_pow.c"],
                    "gsl_pow_7":["sas_pow.c"],
                    "gsl_pow_8":["sas_pow.c"],
                    "gsl_pow_9":["sas_pow.c"],
                    "gsl_pow_int": ["sas_pow.c"],
                    "gsl_sf_bessel_J0":["polevl.c","sas_J0.c"],
                    "gsl_sf_bessel_J1":["polevl.c","sas_J1.c"],
                    "gsl_sf_bessel_JN":["polevl.c", "sas_JN.c"],
                    "gsl_sf_gamma":["sas_gamma.c"],
                    "gsl_sf_bessel_j1": "sph_j1c.c",
                    "gsl_sf_Si":["Si.c"],
                    "gsl_sf_erf": ["polevl.c", "sas_erf.c"]}

def extract_parameters_definition( model_name, tcl_filename ):
    """
    Extracting the definitions of paramters that can be then supplied with the
    parameter table

    :param tcl_file:
    :return:
    """
    tcl_lines = open(tcl_filename).readlines()
    parameters_definition = []
    model_name_upper = "".join(map(lambda p : capwords(p),
                                       model_name.split("_")))
    print "Model name in TCL", model_name_upper, model_name
    for index, line in enumerate(tcl_lines):
        if search(model_name_upper+ " {", line) or search("\""
                                    +model_name_upper+"\" {", line):
            model_def_index = index
    #TODO Some models have extra parameters, so the range with 13 won't work
    model_def_lines = tcl_lines[model_def_index+2:model_def_index+13]
    for def_line in model_def_lines:
        pardef = def_line.split("return \"")[1].strip("\\n\"}\r\n")
        parameters_definition.append(pardef)
    return parameters_definition

def extract_parameters_definition_from_check_cond1( model_name, sasfit_lines):
    """
    Extracting the definitions of paramters that can be then supplied with the
    parameter table

    :param tcl_file:
    :return:
    """
    parameters = []
    for line in sasfit_lines:
        # TODO: There are other define statements, so check if it is not failing
        regm = search("SASFIT_CHECK_COND1", line)
        if regm:
            param = line[regm.end() + 1:].split(",")[3]
            param = param.split(");")[0]
            if param not in parameters:
                parameters.append(param)
    return parameters

def generate_python_header(model_name, output_python_file, parameters_definition):
    """
    Python file header generator
    :param output_python_file:
    :return:
    """
    header_lines = "r\"\"\"\n"

    header_lines += "This file has been automatically gereated by sasfit_convert\n"

    header_lines += "The model calculates an empirical functional form " \
                    "for SAS data characterized\n"
    header_lines += "by "+model_name+"\n\n"
    header_lines += "Definition:\n"
    header_lines += "-----------\n\n"

    header_lines += "References:\n"
    header_lines += "-----------\n\n"

    header_lines += "\"\"\"\n"

    header_lines += "from numpy import inf\n\n"

    header_lines += "name = \""+model_name+"\"\n"
    header_lines += "title = \" \"\n"
    header_lines += "description = \""+parameters_definition[0]+"\"\n"
    header_lines += "category = \" \"\n"

    output_python_file.writelines(header_lines)

def convert_sasfit_model(model_name, sasfit_file, output_c_file,
                         output_python_file, parameters, parameters_definition):
    """
    Main conversion function
    :param sasfit_file:
    :param output_c_file:
    :param output_python_file:
    :return:
    """
    sasfit_lines = open(sasfit_file).readlines()
    output_c_lines = []
    output_intro_lines = []
    output_python_lines = []

    #DO regular expression and remove if it is in line
    c_intro_lines = "///////////////////////////////////////////////////\n"
    c_intro_lines += "//    This is automatically genearted file       //\n"
    c_intro_lines += "//    by sasfit_convert.py                       //\n"
    c_intro_lines += "//    Some editting might be required            //\n"
    c_intro_lines += "///////////////////////////////////////////////////\n\n"

    output_intro_lines.append(c_intro_lines)


    #Add paramters to excluded list, so they don't get redifned - shaky
    exclude_list.append("scalar "+", ".join(parameters))


    #If the compariosn with sasview ETA should be swapped with sld
    #fixed_paramters = []
    #for param in parameters:
    #    if "ETA" in param and not "THETA" in param:
    #        param = param.replace("ETA","sld")
    #    fixed_paramters.append(param)
    #parameters = fixed_paramters

    print "Parameters", parameters
    Iq_lines = "double Iq( double q,"
    Fq_lines = "double Fq( double q, "
    Fq_func = "Fq( q, "
    form_volume_lines = "double form_volume( "
    form_volume_func = "form_volume("
    include_libs = []
    for line in sasfit_lines:
        line = line.strip()
        allowed = 1

        # Replace string in line when need
        #for sub in substitution_dict.keys():
        #    if search(sub, line):
        #        line = line.replace(sub, substitution_dict[sub])

        #Create a new header for Iq function
        #if search("sasfit_ff_"+model_name, line) and not search("src", line):
        if search(r"scalar sasfit_[ff_]+"+model_name+"_f\((.*?)\)", line):
            regm = search(r"sasfit_[ff_]+" + model_name + "_f", line)
            sasfit_Fq = line[regm.start():regm.end()]
            substitution_dict[sasfit_Fq] = "Fq"

            for param in parameters[:-1]:
                Fq_lines+=" double "+param+", "
            Fq_lines+=" double "+parameters[-1]+")"
            output_c_lines.append(Fq_lines+"\n")
            output_intro_lines.append(Fq_lines+";\n")

            allowed = 0
        if search(r"scalar sasfit_[ff_]+"+model_name+"_v\((.*?)\)", line):
            regm = search(r"scalar sasfit_[ff_]+" + model_name + "_v",line)
            sasfit_form_volume = line[regm.start():regm.end()]
            substitution_dict[sasfit_form_volume] = "form_volume"

            for param in parameters[:-1]:
                form_volume_lines+=" double "+param+", "
            form_volume_lines+=" double "+parameters[-1]+")"
            output_c_lines.append(form_volume_lines+"\n")
            output_intro_lines.append(form_volume_lines+";\n")
            allowed = 0
        if search(r"scalar sasfit_[ff_]+"+model_name+"\((.*?)\)", line):
            swap_parameters = ""
            for param in parameters[:-1]:
                swap_parameters += param+", "
                Iq_lines+=" double "+param+", "
            swap_parameters += parameters[-1]
            Iq_lines+=" double "+parameters[-1]
            swap_parameters_def = Iq_lines
            Iq_lines += ")"
            output_c_lines.append(Iq_lines+"\n")
            output_intro_lines.append(Iq_lines+";\n")
            substitution_dict["scalar * param"] = swap_parameters_def
            substitution_dict["param"] = swap_parameters
            allowed = 0
        for banned_term in exclude_list:
            if search(banned_term, line):
                allowed = 0

        for func in libinclude_dict.keys():
            if search(func, line):
                for libfile in libinclude_dict[func]:
                    if not libfile in include_libs:
                        include_libs.append(libfile)

        #Replace string in line when need
        #for sub in substitution_dict.keys():
        #    if search(sub, line):
        #        line = line.replace(sub, substitution_dict[sub])


        #Skip empty lines
        if line=="":
            allowed = 0

        if allowed:
            output_c_lines.append(line+"\n")

    # Replace string in line when need
    out_c_lines = []
    for line in output_c_lines:
        #Replace special functions
        # regm = search(r"sasfit_[ff_]+" + model_name + "_f\((.*?)\)",
        #               line)
        # if regm:
        #     sasfit_Fq = line[regm.start():regm.end()]
        #     line = line.replace(sasfit_Fq, Fq_func)
        # regm = search(r"scalar sasfit_[ff_]+"+model_name+"_v\((.*?)\)", line)
        # if regm:
        #     sasfit_form_volume = line[regm.start():regm.end()]
        #     line = line.replace(sasfit_form_volume, form_volume_func)
        for sub in substitution_dict.keys():
            if search(sub, line):
                line = line.replace(sub, substitution_dict[sub])
        out_c_lines.append(line)

    #output_c_lines += output_Vol_lines + output_Fq_lines + output_Iq_lines

    #TODO: Not exactly sure how to handle this
    header_Iqxy_line = "double Iqxy( double qx, double qy,"
    for param in parameters[:-1]:
        header_Iqxy_line+=" double "+param+","
    header_Iqxy_line+=" double "+parameters[-1]+")"
    output_intro_lines.append(header_Iqxy_line+";\n")
    header_Iqxy_line += "\n"
    header_Iqxy_line+="{\n"
    header_Iqxy_line+="\tdouble q = sqrt(qx*qx + qy*qy);\n"
    header_Iqxy_line+="\treturn Iq( q,"
    for param in parameters[:-1]:
        header_Iqxy_line+=" "+param+","
    header_Iqxy_line+=" "+parameters[-1]+");\n"
    header_Iqxy_line+="}\n"
    out_c_lines.append(header_Iqxy_line)

    #Generating python parameter file
    #It looks from interface that first value is set to 10.0, 4th to 1.0
    #and the rest is 0.0 and apparently standard models takes no more than
    #10 pramateres
    parameters_values = [10.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

    output_python_lines = "#pylint: disable=bad-whitespace, line-too-long\n"
    output_python_lines += "parameters = [\n"
    for index, param in enumerate(parameters):
        try:
            param_def = parameters_definition[index+1]
        except:
            param_def = " "
        #print "Param def", param, param_def
        output_python_lines += " [ \""+param+"\", \t\"\", \t"\
                               +str(parameters_values[index])+", " \
                                "\t[-inf, inf], \t\"\", " \
                                "\t\""+param_def+"\"],\n"
    output_python_lines += "]\n"
    output_python_lines +=" #pylint: enable=bad-whitespace, line-too-long\n\n"
    #FIXME: It should refer to c_file not model name
    output_python_lines +="source = [ "

    for libfile in include_libs:
        libfile = os.path.join("lib", libfile)
        output_python_lines += "\""+libfile+"\", "
    output_python_lines += " \"sasfit_" + model_name + ".c\" ]\n\n"


    output_python_lines +="demo = dict(\n"
    for index, param in enumerate(parameters[:-1]):
        output_python_lines += "\t"+param+" = " \
            +str(parameters_values[index])+",\n"

    output_python_lines += "\t"+parameters[-1]+" = "\
                           +str(parameters_values[len(parameters)-1]) + ")\n"

    output_c_file.writelines(output_intro_lines)

    output_c_file.writelines(out_c_lines)
    output_python_file.writelines(output_python_lines)

def extract_params(model_name, tcl_file, sasfit_file):
    """

    :param model_name:
    :param tcl_file:
    :param sasfit_file:
    :return:
    """
    parameters = []
    parameters_definition = []
    sasfit_lines = open(sasfit_file).readlines()
    try:
        parameters_definition = extract_parameters_definition(model_name,
                                                          tcl_file)
    except:
        parameters_definition = []
        for i in range(11):
            parameters_definition.append("")

    # There a few different ways to extract parameters
    # 1. From sasfit_get_param
    if len(parameters) == 0:
        for line in sasfit_lines:
            regm = search("sasfit_get_param\(", line)
            if regm:
                params = line[regm.end():].strip(");\r\n").split(", ")
                number_of_params = int(params[1])
                parameters = map(lambda p: p.lstrip("&"),
                             params[2:2 + number_of_params])

    # 2. From define statement in the c file
    if len(parameters) == 0:
        for line in sasfit_lines:
            # TODO: There are other define statements, so check if it is not failing
            regm = search("#define", line)
            if regm and search("param->", line):
                param = line[regm.end():]
                regm = search("\s+[\w.-]+( |\t)", param)
                #regm = search("(\s+\t+)\b", param)
                param = param[1:regm.end()]
                param = param.strip("\t")
                param = param.strip(" ")
                parameters.append(param)

    # 2. From SASFIT_CHECK_COND1 in the c file
    if len(parameters) == 0:
        parameters = extract_parameters_definition_from_check_cond1(
                model_name, sasfit_lines)


    # But if 2 above don't work then read it from parameters definition
    if len(parameters) == 0:
        for pardef in parameters_definition[1:]:
            param = pardef.split(":")[0]
            if param != "":
                parameters.append(param)

    #TODO: Quite risky but have to see if there are any consequneces
    if "q" in parameters:
        parameters.remove("q")
    return  parameters, parameters_definition

if __name__=="__main__":
    doc = """
            Script to convert sasfit files to sasmodels
            Usage: python sasfit_convert.py --help
        """
    print doc
    usage = "usage: %prog [options] args"
    option_parser_class = optparse.OptionParser
    parser = option_parser_class( usage = usage, version='0.1' )

    parser.add_option("-f", "--sasfit_file", dest="sasfit_file",
                      help="SASFit c file [OBLIGATORY]")
    parser.add_option("-o", "--output_file", dest="output_file",
                      help="Output c file and python file name [NO EXTENSION]")
    parser.add_option("-t", "--tcl_file", dest="tcl_file",
                      help="TCL file containing parameter definition c file ")

    options, args = parser.parse_args()

    exclude_model_terms = ["sasfit","ff","ff_ff","../",".."]
    if options.output_file:
        model_name = options.output_file
    else:
        #Remove sasfit_ff prefix and .c suffix
        model_name = options.sasfit_file.split("/")[2]
        model_name = "_".join([name_term for name_term in model_name.split("_")
                               if name_term not in exclude_model_terms])
        #model_name = model_name.rstrip(".c")
        model_name = model_name[:-2]
    print model_name, options.sasfit_file
    output_c_filename = "sasfit_"+model_name+".c"
    output_python_filename = "sasfit_"+model_name+".py"

    output_c_file = open(output_c_filename,"w")
    output_python_file =  open(output_python_filename,"w")

    parameters, parameters_definition = extract_params(model_name,
                                        options.tcl_file, options.sasfit_file)

    #Exit when no parameters for model can be defined
    if len(parameters) == 0:
        exit()

    generate_python_header(model_name, output_python_file, parameters_definition)

    convert_sasfit_model(model_name, options.sasfit_file, output_c_file,
                         output_python_file, parameters, parameters_definition)
