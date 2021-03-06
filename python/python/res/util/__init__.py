#  Copyright (C) 2017  Statoil ASA, Norway.
#
#  The file '__init__.py' is part of ERT - Ensemble based Reservoir Tool.
#
#  ERT is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  ERT is distributed in the hope that it will be useful, but WITHOUT ANY
#  WARRANTY; without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE.
#
#  See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html>
#  for more details.
from cwrap import Prototype
import res

class ResUtilPrototype(Prototype):
    lib = res.load("libres_util")

    def __init__(self, prototype, bind=True):
        super(ResUtilPrototype, self).__init__(ResUtilPrototype.lib, prototype, bind=bind)

from .res_log import ResLog