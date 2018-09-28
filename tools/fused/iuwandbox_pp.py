#!/usr/bin/env python
#
# iuwandbox_pp.py
#
# Copyright (C) 2018, Takazumi Shirayanagi
# This software is released under the new BSD License,
# see LICENSE
#

import os
import sys
import codecs
from iutest_pp_strip import IutestPreprocessor

predefined_macros = {
    'NULL': '0',
    '_MSC_VER': None,
    '__MWERKS__': None,
}

iutest_config_macro = {
    'IUTEST_HAS_LIB': '0',
}

expands_macros = [
    'IUTEST_IPP_INLINE',
]

# expand function macros
expand_function_macros = [
    'IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN',
    'IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END',
    'IUTEST_PRAGMA_EXTERN_TEMPLATE_WARN_DISABLE_BEGIN',
    'IUTEST_PRAGMA_EXTERN_TEMPLATE_WARN_DISABLE_END',
    'IUTEST_PRAGMA_CONSTEXPR_CALLED_AT_RUNTIME_WARN_DISABLE_BEGIN',
    'IUTEST_PRAGMA_CONSTEXPR_CALLED_AT_RUNTIME_WARN_DISABLE_END',
    'IUTEST_PRAGMA_MSC_WARN_PUSH',
    'IUTEST_PRAGMA_MSC_WARN_DISABLE',
    'IUTEST_PRAGMA_MSC_WARN_POP',
    'IUTEST_WORKAROUND_MSC_STLSTREAM_C4250',
    'IUTEST_EXPLICIT_TEMPLATE_TYPE_',
]

#
has_features = {
}

has_include = {
}

debug = False

class WandboxPreprocessor:
    pp = IutestPreprocessor(predefined_macros
        , iutest_config_macro
        , expand_function_macros
        , expands_macros
        , has_features
        , has_include)

    def preprocess(self, code, add_macros):
        self.pp.set_debug_flag(debug)
        return self.pp.preprocess(code, add_macros)


def default_pp():
    output_dir = "../../fused-src"
    output = "iutest.wandbox.min.hpp"
    f = codecs.open(os.path.join(output_dir, "iutest.min.hpp"), 'r', 'utf-8-sig')
    code = f.read()
    f.close()
    output_file = codecs.open(os.path.join(output_dir, output), 'w', 'utf-8-sig')
    pp = WandboxPreprocessor()
    code = pp.preprocess(code, None)
    output_file.write(code)
    output_file.close()


def main():
    global debug
    argc = len(sys.argv)
    if argc == 2:
        if sys.argv[1] == 'debug':
            debug = True
    default_pp()

if __name__ == '__main__':
    main()
