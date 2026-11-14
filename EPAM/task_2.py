"""
Task 2 (Hard): Group Anagrams by Value

Write a function `group_anagrams(d)` that takes a dictionary where values are strings,
and returns a new dictionary where each key is a tuple of sorted characters (the anagram signature),
and the value is a list of original keys whose values are anagrams.

Example:
    group_anagrams({'a': 'eat', 'b': 'tea', 'c': 'tan', 'd': 'ate', 'e': 'nat', 'f': 'bat'})
    -> {('a', 'e', 't'): ['a', 'b', 'd'], ('a', 'n', 't'): ['c', 'e'], ('a', 'b', 't'): ['f']}
"""

from collections import defaultdict

def group_anagrams(d):
    """
    Groups dictionary keys by anagram signatures of their values.

    Args:
        d (dict): Dictionary with string values.

    Returns:
        dict: {anagram_signature: [keys]}
    """
    from collections import defaultdict

def group_anagrams(d):
    """
    Groups dictionary keys by anagram signatures of their values.

    Args:
        d (dict): Dictionary with string values.

    Returns:
        dict: {anagram_signature: [keys]}
    """
    groups = defaultdict(list)

    for key, value in d.items():
        signature = tuple(sorted(value))
        groups[signature].append(key)

    return dict(groups)
