import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from EPAM.task_3 import keys_in_cycles

def test_simple_cycle():
    d = {'a': 'b', 'b': 'c', 'c': 'a', 'd': 'e'}
    assert keys_in_cycles(d) == {'a', 'b', 'c'}

def test_multiple_cycles():
    d = {'x': 'y', 'y': 'z', 'z': 'x', 'a': 'b', 'b': 'a'}
    assert keys_in_cycles(d) == {'x', 'y', 'z', 'a', 'b'}

def test_no_cycle():
    d = {'a': 'b', 'b': 'c', 'c': 'd'}
    assert keys_in_cycles(d) == set()

def test_self_cycle():
    d = {'a': 'a', 'b': 'c'}
    assert keys_in_cycles(d) == {'a'}

def test_disconnected_cycles():
    d = {'a': 'b', 'b': 'a', 'c': 'd', 'd': 'c', 'e': 'f'}
    assert keys_in_cycles(d) == {'a', 'b', 'c', 'd'}

def test_empty_dict():
    assert keys_in_cycles({}) == set()
