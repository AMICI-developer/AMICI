"""
Constants
-----------
This module provides a central place to define native python enums and
constants that are used in multiple other modules
"""

import enum


# inheriting from str enables direct comparison to strings, which means that
# the species symbols can be accessed as symbols['species'], which is
# convenient for debugging and symbols[SymbolId.SPECIES], which is how the
# field should be accessed programmatically.
class SymbolId(str, enum.Enum):
    """
    Defines the different fields in the symbol dict to which sbml entities
    get parsed to.
    """
    SPECIES = 'species'
    PARAMETER = 'parameter'
    FIXED_PARAMETER = 'fixed_parameter'
    OBSERVABLE = 'observable'
    EXPRESSION = 'expression'
    SIGMAY = 'sigmay'
    LLHY = 'llhy'
