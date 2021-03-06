#!/usr/bin/env python

"""Utilities used inside nstl to generate definitions automatically."""

import re


def define_token(token):
    """Return the mandatory definition for a token to be used within nstl
       where nstl expects a valid token.

       For example, in order to use an identifier as a method name in a
       nstl type, the definition generated by this function must be written
       for that specific identifier.
    """
    if not isinstance(token, str):
        raise TypeError("{} is not of type {}".format(token, str))
    return "#define NSTL_TOKEN_{} ({})".format(token, " ".join(token))


def define_mangled_name(name, *params):
    """Return a definition appropriate for use as the definition of a :name:
       mangled using :params: as unique particules.

       :params: must be an iterable of names that are to be used as parameter
       to the mangling macro. If no :params: are provided, the macro to be
       generated is assumed an object like macro. To generate a nullary
       function like macro, pass an empty string as sole argument.
    """
    nparams = len(params)
    base = "nstl_mangled_{}".format(name)
    if params and params[0].strip():
        cat_params = "(" + ", _, ".join((base, ) + params) + ")"
        body = "JOY_CAT{}{}".format(len(cat_params.split(",")), cat_params)
    else:
        body = base

    params = ("(" + ", ".join(params) + ")") if params else ""

    return "#define nstl_{}{} {}".format(name, params, body)


def generate(cog, *macros, **options):
    """Generate macro definitions for several :macros:.

       A macro must contain the following:
       * The name of the macro.
       * A list of parameters to the macro.

       The :macros: are parsed and the information is retrieved.
       Examples of valid names are:
       'make_pair(R, T)', 'deref(T)', 'my_type()', 'my_other_type'

       :options: can contain the following:

       A ``token'' field. If True, the NSTL_TOKEN_ macro associated to each
       macro name will be generated.

       A ``mangle'' field. If True, the nstl_mangled_ macro associated to each
       macro name will be generated.
    """
    def _parsed(macro):
        match = re.match(r"(?P<name>\w+)(?P<params>\([\w\s,]*\))?", macro)
        name = match.group("name")
        params = match.group("params")
        params = params.strip("()").split(",") if params else [ ]
        return name, params

    def _generate_macro(name, params):
        to_gen = [ ]
        if options.get('token', False):
            to_gen.append(define_token(name))
        if options.get('mangle', False):
            to_gen.append(define_mangled_name(name, *params))
        return "\n".join(to_gen)

    includes = ["#include <joy/cat.h>",]
    to_gen = list(filter(None, (_generate_macro(*_parsed(macro))
                                                        for macro in macros)))
    if to_gen:
        for line in includes + to_gen:
            cog.outl(line)


if __name__ == "__main__":
    pass
