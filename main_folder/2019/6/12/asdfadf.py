class MyOjbect:
    def __init__(self):
        self.__private_field=10
        self.__private_field2=20

    @classmethod
    def get_private(cls,instance):
        return instance.__private_field,instance.__private_field2
bar = MyOjbect()
assert bar.get_private(bar)==10
print(bar.get_private(bar))
