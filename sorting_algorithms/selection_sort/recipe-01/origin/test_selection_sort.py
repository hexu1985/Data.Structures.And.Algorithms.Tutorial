#!/usr/bin/env python3
"""
Testing the Sorting algorithms
Roman Yasinovskyy, 2017
Karina E. Hoff, 2018
"""


# Specifies the absolute path to the pythonds3 module
import os
import sys

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

import pytest
from random import randint
from selectionSort import selectionSort


class TestSortingMethods:
    """Testing the sorting algorithms"""

    @pytest.fixture(autouse=True)
    def setup_class(self):
        """Setting up"""
        self.lst_to_sort = [randint(100, 999) for _ in range(100)]
        self.test_lst = self.lst_to_sort[:]
        self.test_lst.sort()

    def test_insert_sort(self):
        """Testing Insertion Sort"""
        selectionSort(self.lst_to_sort)
        assert self.lst_to_sort == self.test_lst

if __name__ == "__main__":
    pytest.main(["test_selection_sort.py"])

