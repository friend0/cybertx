import nanopb_pb2 as _nanopb_pb2
from google.protobuf.internal import containers as _containers
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar, Iterable, Optional

DESCRIPTOR: _descriptor.FileDescriptor

class UpdateAll(_message.Message):
    __slots__ = ["channel_values", "line"]
    CHANNEL_VALUES_FIELD_NUMBER: ClassVar[int]
    LINE_FIELD_NUMBER: ClassVar[int]
    channel_values: _containers.RepeatedScalarFieldContainer[int]
    line: int
    def __init__(self, line: Optional[int] = ..., channel_values: Optional[Iterable[int]] = ...) -> None: ...

class UpdateLine(_message.Message):
    __slots__ = ["channel", "channel_value", "line"]
    CHANNEL_FIELD_NUMBER: ClassVar[int]
    CHANNEL_VALUE_FIELD_NUMBER: ClassVar[int]
    LINE_FIELD_NUMBER: ClassVar[int]
    channel: int
    channel_value: int
    line: int
    def __init__(self, line: Optional[int] = ..., channel: Optional[int] = ..., channel_value: Optional[int] = ...) -> None: ...
