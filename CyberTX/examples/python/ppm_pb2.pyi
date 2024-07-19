from google.protobuf.internal import containers as _containers
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Iterable as _Iterable, Optional as _Optional

DESCRIPTOR: _descriptor.FileDescriptor

class UpdateLine(_message.Message):
    __slots__ = ("line", "channel", "channel_value")
    LINE_FIELD_NUMBER: _ClassVar[int]
    CHANNEL_FIELD_NUMBER: _ClassVar[int]
    CHANNEL_VALUE_FIELD_NUMBER: _ClassVar[int]
    line: int
    channel: int
    channel_value: int
    def __init__(self, line: _Optional[int] = ..., channel: _Optional[int] = ..., channel_value: _Optional[int] = ...) -> None: ...

class UpdateAll(_message.Message):
    __slots__ = ("line", "channel_values")
    LINE_FIELD_NUMBER: _ClassVar[int]
    CHANNEL_VALUES_FIELD_NUMBER: _ClassVar[int]
    line: int
    channel_values: _containers.RepeatedScalarFieldContainer[int]
    def __init__(self, line: _Optional[int] = ..., channel_values: _Optional[_Iterable[int]] = ...) -> None: ...
