import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from EPAM.task_1 import second_highest_value_key

def test_positive_case():
    assert second_highest_value_key({'a': 1, 'b': 2, 'c': 3, 'd': 4}) == 'c'
    assert second_highest_value_key({'x': 10, 'y': 20, 'z': 30}) == 'y'

def test_negative_case():
    assert second_highest_value_key({'a': 4, 'b': 4, 'c': 4}) is None
    assert second_highest_value_key({}) is None
    assert second_highest_value_key({'a': 1}) is None

def test_space_case():
    assert second_highest_value_key({'a': 1000000, 'b': 999999, 'c': 1000000}) == 'b'

def test_time_case():
    large_dict = {str(i): i for i in range(1000000)}
    assert second_highest_value_key(large_dict) == str(999998)

def test_edge_case():
    assert second_highest_value_key({'a': 2, 'b': 2, 'c': 1}) == 'c'
    assert second_highest_value_key({'a': -1, 'b': -2, 'c': -3}) == 'b'
