#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
A script to generate a table for overalping SasView SasFit model functions
The script read list of models filenames
1) Read sasmodels and extract names, parameters definition (parse the table)
2) Initiate a dictonary with the names, so one can check the overlap
2) Do the same for SASFit models for which
"""

__author__ = "Wojtek Potrzebowski"
__maintainer__ = "Wojtek Potrzebowski"
__email__ = "Wojciech.Potrzebowski@esss.se"

import optparse
import sys
from re import search
from string import replace
from string import capwords
from prettytable import PrettyTable

sys.path.append('/Users/wojciechpotrzebowski/sasmodels_sasfit/sasmodels/sasmodels/models')

sasview_dict = {}
sasfit_dict = {}

def generate_table(sasmodels_dict, sasfit_dict, cpu_list, gpu_list):
    """
    Generates a table in a wiki format that can be then copy pased.
    Two dictionaries contain are indexed by model name and store
    parameters table

    :param sasmodels_dict:
    :param sasfit_dict:
    :return:
    """
    x = PrettyTable(["SasView Model", "SasView Description",
                     "SasView Parameters", "SasFit Model",
                     "SasFit Description", "SasFit Parameters",
                     "Compile CPU", "Compile GPU"],
                    header_color='bold'
                    )
    x.align["SasView Model"] = "c"
    x.align["SasView Description"] = "l"
    x.align["SasView Parameters"] = "l"

    x.align["SasFit Model"] = "c"
    x.align["SasFit Description"] = "l"
    x.align["SasFit Parameters"] = "l"
    x.align["Compile CPU"] = "c"
    x.align["Compile GPU"] = "c"

    overlaping_models = []
    nonoverlaping_sasview_models = []
    model_names_sv = {}
    for sasview_model in sasview_dict.keys():
        #Different version of sasfit_models
        #No underscore
        sasfit_model_no = sasview_model.replace("_","")
        #No underscore and capitalized letters
        sasfit_model_nou = "".join(map(lambda p : capwords(p),
                                       sasview_model.split("_")))
        sasfit_model_cap = sasview_model.upper()

        #Checking different naming options
        if sasview_model in sasfit_dict:
            model_names_sv[sasview_model] = sasview_model
            overlaping_models.append(sasview_model)
        elif sasfit_model_no in sasfit_dict:
            model_names_sv[sasview_model] = sasfit_model_no
            overlaping_models.append(sasview_model)
            overlaping_models.append(sasfit_model_no)
        elif sasfit_model_nou in sasfit_dict:
            model_names_sv[sasview_model] = sasfit_model_nou
            overlaping_models.append(sasview_model)
            overlaping_models.append(sasfit_model_nou)
        elif sasfit_model_cap in sasfit_dict:
            model_names_sv[sasview_model] = sasfit_model_cap
            overlaping_models.append(sasview_model)
            overlaping_models.append(sasfit_model_cap)
        else:
            nonoverlaping_sasview_models.append(sasview_model)

    #Print overlapping models
    for sasview_model in sasview_dict.keys():
        if sasview_model in overlaping_models:
            descs_sv = sasview_dict[sasview_model][0].replace("\n"," ")
            #params_sv = []
            # map( params_sv.extend, sasview_dict[sasview_model][1])
            params_sv = sasview_dict[sasview_model][1]
            params_sv ="br".join(str(x) for x in params_sv)
            params_sv = params_sv.replace("]br["," br ")
            params_sv = params_sv[1:-1]
            #for each of the paramters repeat it with some step and change color
            sasfit_model = model_names_sv[sasview_model]
            descs_sf = sasfit_dict[sasfit_model][0].replace("\n"," ")

            params_sf = sasfit_dict[sasfit_model][1]
            params_sf = "br".join(str(x) for x in params_sf)
            params_sf = params_sf.replace("]br[", " br ")
            params_sf = params_sf[1:-1]
            #map( params_sf.extend, sasfit_dict[sasfit_model][1])

            compiled_cpu = "NoImg"
            compiled_gpu = "NoImg"
            if "sasfit_"+sasfit_model in cpu_list:
                compiled_cpu = "YesImg"
            if "sasfit_"+sasfit_model in gpu_list:
                compiled_gpu = "YesImg"
            x.add_row([sasview_model, descs_sv, params_sv,
                       sasfit_model, descs_sf, params_sf,
                       compiled_cpu, compiled_gpu])

    #Print non-overlapping SasView models
    for sasview_model in sasview_dict.keys():
        if sasview_model in nonoverlaping_sasview_models:
            descs = sasview_dict[sasview_model][0].replace("\n"," ")

            #map( params.extend, sasview_dict[sasview_model][1])
            #params =", ".join(str(x) for x in params)
            params = sasview_dict[sasview_model][1]
            params = "br".join(str(x) for x in params)
            params = params.replace("]br[", " br ")
            params = params[1:-1]
            x.add_row([sasview_model, descs, params, "", "","", "N/A", "N/A"])

    #Last print non-overlaping SASFit models
    for sasfit_model in sasfit_dict.keys():
        if not sasfit_model in overlaping_models:
            descs = sasfit_dict[sasfit_model][0].replace("\n", " ")
            #params = []
            #map( params.extend, sasfit_dict[sasfit_model][1])
            #params =", ".join(str(x) for x in params)
            params = sasfit_dict[sasfit_model][1]
            params = "br".join(str(x) for x in params)
            params = params.replace("]br[", " br ")
            params = params[1:-1]
            compiled_cpu = "NoImg"
            compiled_gpu = "NoImg"
            if "sasfit_"+sasfit_model in cpu_list:
                compiled_cpu = "YesImg"
            if "sasfit_"+sasfit_model in gpu_list:
                compiled_gpu = "YesImg"
            x.add_row(["", "", "", sasfit_model, descs, params,
                       compiled_cpu, compiled_gpu])

    return x

def extract_pardesc_table(model_dict, model_name):
    """
    Reads in specific filename and extracts description and parameters table
    :param model_name:
    :param model_dict:
    :return:
    """
    print model_name
    model_module = __import__(model_name)
    parameters = model_module.parameters
    description = model_module.description

    if model_name[:7] == "sasfit_":
            model_name = model_name[7:]
    model_dict[model_name] = [description, parameters]



if __name__=="__main__":
    doc = """
        Script to generate overlap table between SASFit and Sasmodels
        Usage: python sasfit_sasview_overlap.py --help
        """
    print doc
    usage = "usage: %prog [options] args"
    option_parser_class = optparse.OptionParser
    parser = option_parser_class( usage = usage, version='0.1' )

    parser.add_option("-l", "--sasmodels_list", dest="sasmodels_file",
                    help="List of sasmodel files [OBLIGATORY]")
    parser.add_option("-m", "--sasfit_list", dest="sasfit_file",
                    help="List of sasfit files [OBLIGATORY]")
    parser.add_option("-c", "--cpulist_file", dest="cpu_file",
                    help="List of cpu compiled files [OBLIGATORY]")
    parser.add_option("-g", "--gpulist_file", dest="gpu_file",
                    help="List of GPU compiled files [OBLIGATORY]")
    parser.add_option("-o", "--output_file", dest="output_file",
                    help="Output table file [OBLIGATORY]")

    options, args = parser.parse_args()

    cpu_list = map( lambda model: model.strip("\n"),
                    open(options.cpu_file).readlines())
    gpu_list = map(lambda model: model.strip("\n"),
                   open(options.gpu_file).readlines())
    for model_file in open(options.sasfit_file).readlines():
        #model_name = model_file.rstrip(".py\n")
        model_name = model_file.rstrip("\n")
        extract_pardesc_table(sasfit_dict,model_name)

    for model_file in open(options.sasmodels_file).readlines():
        #model_name = model_file.rstrip(".py\n")
        model_name = model_file.rstrip("\n")
        extract_pardesc_table(sasview_dict, model_name)

    table_lines = generate_table(sasview_dict,sasfit_dict, cpu_list, gpu_list)
    table_lines.format = True
    output_html = table_lines.get_html_string(attributes={"name":"my_table"})
    open(options.output_file,"w").write(output_html)