import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from EPAM.task_2 import group_anagrams

def test_positive_case():
    d = {'a': 'eat', 'b': 'tea', 'c': 'tan', 'd': 'ate', 'e': 'nat', 'f': 'bat'}
    result = group_anagrams(d)
    assert set(result[('a', 'e', 't')]) == {'a', 'b', 'd'}
    assert set(result[('a', 'n', 't')]) == {'c', 'e'}
    assert set(result[('a', 'b', 't')]) == {'f'}

def test_negative_case():
    d = {'a': 'abc', 'b': 'def', 'c': 'ghi'}
    result = group_anagrams(d)
    assert result == {('a', 'b', 'c'): ['a'], ('d', 'e', 'f'): ['b'], ('g', 'h', 'i'): ['c']}

def test_space_case():
    d = {'a': '', 'b': '', 'c': ''}
    result = group_anagrams(d)
    assert result == {(): ['a', 'b', 'c']}

def test_time_case():
    d = {str(i): 'abc' for i in range(1000)}
    result = group_anagrams(d)
    assert result == {('a', 'b', 'c'): [str(i) for i in range(1000)]}

def test_edge_case():
    d = {'a': 'a', 'b': 'A'}
    result = group_anagrams(d)
    assert ('a',) in result
    assert ('A',) in result


