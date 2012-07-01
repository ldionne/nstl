#!/usr/bin/env python3

"""Utilities used inside nstl to generate stuff automatically."""

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
       mangled using :attr: as unique particules.

       :params: must be an iterable of names that are to be used as parameter
       to the mangling macro. If no :params: are provided, the macro to be
       generated is assumed an object like macro. To generate a nullary
       function like macro, pass an empty string as sole argument.
    """
    nparams = len(params)
    base = "nstl_mangled_{0}".format(name)
    if params and params[0].strip():
        cat_params = "(" + ", _, ".join((base, ) + params) + ")"
        body = "JOY_CAT{0}{1}".format(len(cat_params.split(",")), cat_params)
    else:
        body = base

    params = ("(" + ", ".join(params) + ")") if params else ""

    return """#define nstl_{0}{1} {2}""".format(name, params, body)


def forward_to_implement(attr):
    """Return a definition appropriate to forward an instruction directly to
       the implement instruction when creating nstl types.
    """
    return """#define NSTL_INSTRUCTION_{0}(s, self, implementation) \\
    NSTL_INSTRUCTION_implement(s, self, {0}, implementation)""".format(attr)


def generate_attributes(*attributes, implement=False, token=True):
    """Generate definitions for several :attributes:.

       An attribute must contain the following:
       * The name of the attribute.
       * A list of parameters to the attribute.

       The :attributes: iterable is parsed and the information is retrieved.
       Examples of valid attributes are:
       'make_pair(R, T)', 'deref(T)', 'my_type()', 'my_other_type'

       If :implement: is False (default), the definition of the attribute
       as a forwarding to NSTL_INSTRUCTION_implement is not generated, so
       the :attributes: can not be used as implement instructions without
       defining the instruction manually.

       If :token: is True (default), the NSTL_TOKEN_ macro associated to each
       attribute is generated.

       In all cases, the mangled name of the attribute is generated.
    """
    def _parsed(attr):
        match = re.match(r"(?P<name>\w+)(?P<params>\([\w\s,]*\))?", attr)
        name = match.group("name")
        params = match.group("params")
        params = params.strip("()").split(",") if params else [ ]
        return name, params

    def _generate_attribute(name, params):
        to_gen = [ ]
        if token:
            to_gen.append(define_token(name))
        if implement:
            to_gen.append(forward_to_implement(name))
        to_gen.append(define_mangled_name(name, *params))
        return "\n".join(to_gen)

    to_gen = [ ]
    for attr in attributes:
        name, params = _parsed(attr)
        to_gen.append(_generate_attribute(name, params))
    return "\n".join(to_gen)


if __name__ == "__main__":
    pass