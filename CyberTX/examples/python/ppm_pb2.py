# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: ppm.proto
# Protobuf Python Version: 5.26.1
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\tppm.proto\x12\x07\x63ybertx\"B\n\nUpdateLine\x12\x0c\n\x04line\x18\x01 \x01(\x05\x12\x0f\n\x07\x63hannel\x18\x02 \x01(\x05\x12\x15\n\rchannel_value\x18\x03 \x01(\x05\"5\n\tUpdateAll\x12\x0c\n\x04line\x18\x01 \x01(\x05\x12\x1a\n\x0e\x63hannel_values\x18\x02 \x03(\x05\x42\x02\x10\x01\x42\'Z%github.com/friend0/cybertx/clients/gob\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'ppm_pb2', _globals)
if not _descriptor._USE_C_DESCRIPTORS:
  _globals['DESCRIPTOR']._loaded_options = None
  _globals['DESCRIPTOR']._serialized_options = b'Z%github.com/friend0/cybertx/clients/go'
  _globals['_UPDATEALL'].fields_by_name['channel_values']._loaded_options = None
  _globals['_UPDATEALL'].fields_by_name['channel_values']._serialized_options = b'\020\001'
  _globals['_UPDATELINE']._serialized_start=22
  _globals['_UPDATELINE']._serialized_end=88
  _globals['_UPDATEALL']._serialized_start=90
  _globals['_UPDATEALL']._serialized_end=143
# @@protoc_insertion_point(module_scope)
