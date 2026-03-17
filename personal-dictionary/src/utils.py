class AdditionalFunctions:

    def func_lower(self, string):
        return string.lower()

    def check_length(self, lst):
        return len(lst) != 0

    def check_type(self, object):
        return True if object.isdigit() else False