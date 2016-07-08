#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Program to convert old plugin models

"""


__author__ = "Wojtek Potrzebowski"
__maintainer__ = "Wojtek Potrzebowski"
__email__ = "Wojciech.Potrzebowski@esss.se"

import os
import optparse
from re import search
from re import findall

#We are vaoiding math
substitution_dict = {"math.":""}

def generate_python_header(model_name, output_python_file, description):
    """
    Python file header generator
    :param output_python_file:
    :return:
    """
    header_lines = "r\"\"\"\n"

    header_lines += "This file has been automatically gereated by conversion script\n"

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
    header_lines += "description = \""+description+"\"\n"
    header_lines += "category = \" \"\n"

    output_python_file.writelines(header_lines)

def convert_old_plugin(model_name, output_python_file, parameters):
    """
    Main conversion function
    :param model_name:
    :param output_python_file:
    :return:
    """

    output_python_lines = "#pylint: disable=bad-whitespace, line-too-long\n"
    output_python_lines += "parameters = [\n"
    for param in parameters.keys():
        #TODO: Left if there is any parameter definition available
        param_def = " "
        output_python_lines += " [ \""+param+"\", \t\"\", \t"\
                               +str(parameters[param])+", " \
                                "\t[-inf, inf], \t\"\", " \
                                "\t\""+param_def+"\"],\n"
    output_python_lines += "]\n"
    output_python_lines +=" #pylint: enable=bad-whitespace, line-too-long\n\n"

    #Instert functions here
    output_python_lines +="def Iq(x "
    for param in parameters.keys():
        output_python_lines+=", "+param
    output_python_lines+="):\n"

    plugin_lines = open(model_name+".py").readlines()
    add_lines = 0
    for line in  plugin_lines:
        #Swap parmeters
        regm = search(r"self.params\['(.*?)'\]", line)
        if regm:
            param = line[regm.start():regm.end()][13:-2]
            larg =  line.split("=")[0]
            line = larg +" = " + param+"\n"
        if add_lines:
            output_python_lines +=line

        #From def function until return
        if search(r"def function\((.*?)\)", line):
            add_lines=1
        if search(r"return (.*?) ## MODIFY ONLY RESULT.", line):
            add_lines=0

    #Demo dict can be added
    # output_python_lines +="demo = dict(\n"
    #
    # for param in parameters.keys():
    #     output_python_lines += "\t"+param+" = " \
    #         +str(parameters[param])+",\n"
    #
    # output_python_lines += ")\n"

    #Finally substition strings
    for sub in substitution_dict.keys():
        if search(sub, output_python_lines):
            output_python_lines = output_python_lines.replace(sub, substitution_dict[sub])
    output_python_file.writelines(output_python_lines)

def extract_params(model_name):
    """

    :param model_name:
    :return:
    """

    #TODO: It will be best to load modules but beacuuse od loading erros doesn't work
    model_module = __import__(model_name)
    parameters = model_module.params
    description = model_module.description

    return  parameters, description

def parse_params(model_name):
    """

    :param model_name:
    :return:
    """

    #TODO: It will be best to load modules but beacuuse od loading erros doesn't work

    plugin_lines = open(model_name+".py").readlines()
    parse_lines = 0
    #desc_lines = 0
    parameters = {}
    description = ""
    for idx, line in  enumerate(plugin_lines):
        #From def function until return
        if search(r"def __init__\((.*?)\)", line):
            parse_lines=1
        if search(r"def function\((.*?)\)", line):
            parse_lines=0

        if parse_lines:
            regm = search(r"self.params\['(.*?)'\]", line)
            if regm:
                param = line[regm.start():regm.end()][13:-2]
                value = findall("=[\s+][-+]?\d*\.*\d+", line)
                value = float(value[0][1:])
                parameters[param] = value
            if search(r"self.description = \"\"\"", line):
                #TODO: Will need to fix it takes the first line only
                description+=plugin_lines[idx+1].strip("\n\r")
            #if search(r"\"\"\"[\s+]## <-----", line):
            #   desc_lines = 0


    return  parameters, description


if __name__=="__main__":
    doc = """
            Script to convert old plugin models to sasmodels
            Usage: python convert_old_plugins.py --help
        """
    print doc
    usage = "usage: %prog [options] args"
    option_parser_class = optparse.OptionParser
    parser = option_parser_class( usage = usage, version='0.1' )

    parser.add_option("-f", "--plugin_file", dest="plugin_file",
                      help="Old plugin file [OBLIGATORY]")
    options, args = parser.parse_args()

    #Remove .py
    model_name = options.plugin_file[:-3]
    output_python_filename = "converted_"+model_name+".py"

    output_python_file =  open(output_python_filename,"w")

    parameters, description = parse_params(model_name)


    generate_python_header(model_name, output_python_file,
                           description)

    convert_old_plugin(model_name, output_python_file, parameters)
