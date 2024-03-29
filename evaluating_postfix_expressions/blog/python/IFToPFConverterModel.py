#!/usr/bin/env python3

from io import StringIO
from Scanner import Scanner
from IFToPFConverter import IFToPFConverter

class IFToPFConverterModel:
    def convert(self, sourceStr):
        self.converter = IFToPFConverter(Scanner(sourceStr))
        postfix = self.converter.convert()
        return postfix

    def format(self, sourceStr):
        normalizedStr = ""
        scanner = Scanner(sourceStr);
        while scanner.hasNext():
            normalizedStr += str(scanner.next()) + " "
        return normalizedStr;   

    def conversionStatus(self):
        return str(self.converter)

def test_converter(converter, sourceStr):
    try:
        print(converter.format(sourceStr))
        print(converter.convert(sourceStr))
    except Exception as e:
        print(e)
        print(converter.conversionStatus())

def main():
    # A simple tester program
    converter = IFToPFConverterModel()
    test_converter(converter, "8 + 2 * 3")
    test_converter(converter, "(8 + 2) * 3")
    test_converter(converter, "8 / 9 * 5")
    test_converter(converter, "8 / 9 )")

if __name__ == "__main__":
    main()
