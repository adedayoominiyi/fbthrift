#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import folly.iobuf as __iobuf
import thrift.py3.types
import thrift.py3.exceptions
from thrift.py3.types import NOTSET, NOTSETTYPE
import typing as _typing
from typing_extensions import Final

import sys
import itertools


__property__ = property


class Foo(thrift.py3.types.Struct, _typing.Hashable, _typing.Iterable[_typing.Tuple[str, _typing.Any]]):
    MyInt: Final[int] = ...

    def __init__(
        self, *,
        MyInt: _typing.Optional[int]=None
    ) -> None: ...

    def __call__(
        self, *,
        MyInt: _typing.Union[int, NOTSETTYPE, None]=NOTSET
    ) -> Foo: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['Foo'], bytes]]: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...
    def __bool__(self) -> bool: ...
    def __hash__(self) -> int: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'Foo') -> bool: ...
    def __gt__(self, other: 'Foo') -> bool: ...
    def __le__(self, other: 'Foo') -> bool: ...
    def __ge__(self, other: 'Foo') -> bool: ...


