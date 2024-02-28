#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Analyse syntaxique LL(1) de la BNF G1 du chapitre 3.
"""

import io

#################################
# lexer


TOKENS = tuple(range(4))
a, b, c, END = TOKENS  # END = token spécial de fin de fichier
TOKEN_NAME = 'a', 'b', 'c', ''


SWITCH = {'': END,
          'a': a,
          'b': b,
          'c': c}


def next_token():
    return SWITCH[stream.read(1)]


#################################
# generic functions of LL(1) parsing


def init_parser(txt: str):
    global current, stream
    stream = io.StringIO(txt)
    current = next_token()
