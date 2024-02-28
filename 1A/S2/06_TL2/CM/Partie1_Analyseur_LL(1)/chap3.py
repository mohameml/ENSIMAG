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


class Error(Exception):
    pass


def parse_token(token):
    global current
    if current != token:
        raise Error('found token ' + repr(TOKEN_NAME[current]) +
                    ' but expected ' + repr(TOKEN_NAME[token]))
    if current != END:
        current = next_token()


def select(rules):
    return rules[current]


def mk_rules(default_rule, directed_rules):
    rules = [default_rule]*len(TOKENS)
    for director, rule in directed_rules:
        for token in director:
            assert rules[token] is default_rule, \
                "Incorrect director: token {0} both associated" + \
                " to rules {1} and {2}".format(repr(TOKEN_NAME[token]),
                                               rules[token], rule)
            rules[token] = rule
    return rules

#################################
# version 1 (without select and mkrules)


def parse_v1(txt: str) -> str:
    init_parser(txt)
    w = parse_S_v1()
    parse_token(END)
    return w


def parse_S_v1():
    w1 = parse_O_v1()
    parse_token(c)
    return w1 + "a"


def parse_O_v1():
    if current in [a, b]:
        w1 = parse_P_v1()
        return w1 + "c"
    else:
        return ""


def parse_P_v1():
    if current == b:
        parse_token(b)
        return ""
    else:
        parse_token(a)
        w1 = parse_P_v1()
        parse_token(c)
        w2 = parse_P_v1()
        return "b" + w1 + "ca" + w2

#################################
# version 2 (with select and mkrules)


def parse_v2(txt: str) -> str:
    init_parser(txt)
    w = parse_S_v2()
    parse_token(END)
    return w


def parse_S_v2():
    w1 = parse_O_v2()
    parse_token(c)
    return w1 + "a"


def parse_O_v2():
    return select(O_RULES_v2)()


def O_ab_v2():
    w1 = parse_P_v2()
    return w1 + "c"


def O_c_v2():
    return ""


O_RULES_v2 = mk_rules(O_c_v2, [([a, b], O_ab_v2)])


def parse_P_v2():
    return select(P_RULES_v2)()


def P_b_v2():
    parse_token(b)
    return ""


def P_a_v2():
    parse_token(a)
    w1 = parse_P_v2()
    parse_token(c)
    w2 = parse_P_v2()
    return "b" + w1 + "ca" + w2


P_RULES_v2 = mk_rules(P_a_v2, [([b], P_b_v2)])

#################################
# version 3 (with select and mkrules)


def parse_v3(txt: str) -> str:
    init_parser(txt)
    w = parse_S_v3()
    parse_token(END)
    return w


def parse_S_v3():
    w1 = parse_O_v3()
    parse_token(c)
    return w1 + "a"


def parse_O_v3():
    return select(O_RULES_v3)()


def O_ab_v3():
    w1 = parse_P_v3()
    return w1 + "c"


def O_c_v3():
    return ""


O_RULES_v3 = mk_rules(O_ab_v3, [([c], O_c_v3)])


def parse_P_v3():
    return select(P_RULES_v3)()


def P_b_v3():
    parse_token(b)
    return ""


def P_a_v3():
    parse_token(a)
    w1 = parse_P_v3()
    parse_token(c)
    w2 = parse_P_v3()
    return "b" + w1 + "ca" + w2


P_RULES_v3 = mk_rules(P_b_v3, [([a], P_a_v3)])


#####
# tests
def check(txt: str, result: str):
    assert len(txt) == len(result)
    s = {'a': 'b', 'b': 'c', 'c': 'a'}
    for i, c in enumerate(txt):
        assert s[c] == result[i]


def test(parse, txt: str, ok: bool = True):
    print("@ input:", txt)
    try:
        w = parse(txt)
        print("@ result:", w)
        print()
        assert ok
        check(txt, w)
    except Error as e:
        print("@ error:", e)
        print()
        assert not ok


def exec_tests(parse):
    print("@@@@@@ test: ", parse)
    test(parse, "ca", False)
    test(parse, "ac", False)
    test(parse, "abc", False)
    test(parse, "abcb", False)
    test(parse, "c")
    test(parse, "bc")
    test(parse, "abcbc")
    test(parse, "abcabcbc")
    test(parse, "aabcbcbc")


exec_tests(parse_v1)
exec_tests(parse_v2)
exec_tests(parse_v3)
