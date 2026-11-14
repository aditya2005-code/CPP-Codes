"""
Task 1 (Intermediate): Find Key with Second Highest Value

Write a function `second_highest_value_key(d)` that takes a dictionary of {key: int value} and returns the key with the second highest unique value.
If there is no such key, return None.

Example:
    second_highest_value_key({'a': 1, 'b': 2, 'c': 3, 'd': 4}) -> 'c'
    second_highest_value_key({'a': 4, 'b': 4, 'c': 4}) -> None
"""

def second_highest_value_key(d):
    """
    Returns the key with the second highest unique value in the dictionary.
    If there is no such key, returns None.

    Args:
        d (dict): Dictionary with int values.

    Returns:
        key or None: The key with the second highest unique value, or None if not applicable.
    """
    first = second = None
    first_key = second_key = None

    for key, val in d.items():
        if first is None or val > first:
            second = first
            second_key = first_key

            first = val
            first_key = key

        elif val != first and (second is None or val > second):
            second = val
            second_key = key

    return second_key
