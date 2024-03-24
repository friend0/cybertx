// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_message_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_message_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_message_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_message_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_message_2eproto;
namespace cybertx {
namespace messages {
class PPMUpdate;
struct PPMUpdateDefaultTypeInternal;
extern PPMUpdateDefaultTypeInternal _PPMUpdate_default_instance_;
class PPMUpdateAll;
struct PPMUpdateAllDefaultTypeInternal;
extern PPMUpdateAllDefaultTypeInternal _PPMUpdateAll_default_instance_;
}  // namespace messages
}  // namespace cybertx
PROTOBUF_NAMESPACE_OPEN
template<> ::cybertx::messages::PPMUpdate* Arena::CreateMaybeMessage<::cybertx::messages::PPMUpdate>(Arena*);
template<> ::cybertx::messages::PPMUpdateAll* Arena::CreateMaybeMessage<::cybertx::messages::PPMUpdateAll>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace cybertx {
namespace messages {

// ===================================================================

class PPMUpdate final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:cybertx.messages.PPMUpdate) */ {
 public:
  inline PPMUpdate() : PPMUpdate(nullptr) {}
  ~PPMUpdate() override;
  explicit PROTOBUF_CONSTEXPR PPMUpdate(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PPMUpdate(const PPMUpdate& from);
  PPMUpdate(PPMUpdate&& from) noexcept
    : PPMUpdate() {
    *this = ::std::move(from);
  }

  inline PPMUpdate& operator=(const PPMUpdate& from) {
    CopyFrom(from);
    return *this;
  }
  inline PPMUpdate& operator=(PPMUpdate&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PPMUpdate& default_instance() {
    return *internal_default_instance();
  }
  static inline const PPMUpdate* internal_default_instance() {
    return reinterpret_cast<const PPMUpdate*>(
               &_PPMUpdate_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PPMUpdate& a, PPMUpdate& b) {
    a.Swap(&b);
  }
  inline void Swap(PPMUpdate* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PPMUpdate* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PPMUpdate* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PPMUpdate>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PPMUpdate& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PPMUpdate& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PPMUpdate* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "cybertx.messages.PPMUpdate";
  }
  protected:
  explicit PPMUpdate(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLineFieldNumber = 1,
    kChannelFieldNumber = 2,
    kChannelValueFieldNumber = 3,
  };
  // int32 line = 1;
  void clear_line();
  int32_t line() const;
  void set_line(int32_t value);
  private:
  int32_t _internal_line() const;
  void _internal_set_line(int32_t value);
  public:

  // int32 channel = 2;
  void clear_channel();
  int32_t channel() const;
  void set_channel(int32_t value);
  private:
  int32_t _internal_channel() const;
  void _internal_set_channel(int32_t value);
  public:

  // int32 channel_value = 3;
  void clear_channel_value();
  int32_t channel_value() const;
  void set_channel_value(int32_t value);
  private:
  int32_t _internal_channel_value() const;
  void _internal_set_channel_value(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:cybertx.messages.PPMUpdate)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int32_t line_;
  int32_t channel_;
  int32_t channel_value_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_message_2eproto;
};
// -------------------------------------------------------------------

class PPMUpdateAll final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:cybertx.messages.PPMUpdateAll) */ {
 public:
  inline PPMUpdateAll() : PPMUpdateAll(nullptr) {}
  ~PPMUpdateAll() override;
  explicit PROTOBUF_CONSTEXPR PPMUpdateAll(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PPMUpdateAll(const PPMUpdateAll& from);
  PPMUpdateAll(PPMUpdateAll&& from) noexcept
    : PPMUpdateAll() {
    *this = ::std::move(from);
  }

  inline PPMUpdateAll& operator=(const PPMUpdateAll& from) {
    CopyFrom(from);
    return *this;
  }
  inline PPMUpdateAll& operator=(PPMUpdateAll&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PPMUpdateAll& default_instance() {
    return *internal_default_instance();
  }
  static inline const PPMUpdateAll* internal_default_instance() {
    return reinterpret_cast<const PPMUpdateAll*>(
               &_PPMUpdateAll_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PPMUpdateAll& a, PPMUpdateAll& b) {
    a.Swap(&b);
  }
  inline void Swap(PPMUpdateAll* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PPMUpdateAll* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PPMUpdateAll* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PPMUpdateAll>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PPMUpdateAll& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PPMUpdateAll& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PPMUpdateAll* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "cybertx.messages.PPMUpdateAll";
  }
  protected:
  explicit PPMUpdateAll(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kChannelValuesFieldNumber = 2,
    kLineFieldNumber = 1,
  };
  // repeated int32 channel_values = 2;
  int channel_values_size() const;
  private:
  int _internal_channel_values_size() const;
  public:
  void clear_channel_values();
  private:
  int32_t _internal_channel_values(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      _internal_channel_values() const;
  void _internal_add_channel_values(int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      _internal_mutable_channel_values();
  public:
  int32_t channel_values(int index) const;
  void set_channel_values(int index, int32_t value);
  void add_channel_values(int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      channel_values() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      mutable_channel_values();

  // int32 line = 1;
  void clear_line();
  int32_t line() const;
  void set_line(int32_t value);
  private:
  int32_t _internal_line() const;
  void _internal_set_line(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:cybertx.messages.PPMUpdateAll)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t > channel_values_;
  mutable std::atomic<int> _channel_values_cached_byte_size_;
  int32_t line_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_message_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PPMUpdate

// int32 line = 1;
inline void PPMUpdate::clear_line() {
  line_ = 0;
}
inline int32_t PPMUpdate::_internal_line() const {
  return line_;
}
inline int32_t PPMUpdate::line() const {
  // @@protoc_insertion_point(field_get:cybertx.messages.PPMUpdate.line)
  return _internal_line();
}
inline void PPMUpdate::_internal_set_line(int32_t value) {
  
  line_ = value;
}
inline void PPMUpdate::set_line(int32_t value) {
  _internal_set_line(value);
  // @@protoc_insertion_point(field_set:cybertx.messages.PPMUpdate.line)
}

// int32 channel = 2;
inline void PPMUpdate::clear_channel() {
  channel_ = 0;
}
inline int32_t PPMUpdate::_internal_channel() const {
  return channel_;
}
inline int32_t PPMUpdate::channel() const {
  // @@protoc_insertion_point(field_get:cybertx.messages.PPMUpdate.channel)
  return _internal_channel();
}
inline void PPMUpdate::_internal_set_channel(int32_t value) {
  
  channel_ = value;
}
inline void PPMUpdate::set_channel(int32_t value) {
  _internal_set_channel(value);
  // @@protoc_insertion_point(field_set:cybertx.messages.PPMUpdate.channel)
}

// int32 channel_value = 3;
inline void PPMUpdate::clear_channel_value() {
  channel_value_ = 0;
}
inline int32_t PPMUpdate::_internal_channel_value() const {
  return channel_value_;
}
inline int32_t PPMUpdate::channel_value() const {
  // @@protoc_insertion_point(field_get:cybertx.messages.PPMUpdate.channel_value)
  return _internal_channel_value();
}
inline void PPMUpdate::_internal_set_channel_value(int32_t value) {
  
  channel_value_ = value;
}
inline void PPMUpdate::set_channel_value(int32_t value) {
  _internal_set_channel_value(value);
  // @@protoc_insertion_point(field_set:cybertx.messages.PPMUpdate.channel_value)
}

// -------------------------------------------------------------------

// PPMUpdateAll

// int32 line = 1;
inline void PPMUpdateAll::clear_line() {
  line_ = 0;
}
inline int32_t PPMUpdateAll::_internal_line() const {
  return line_;
}
inline int32_t PPMUpdateAll::line() const {
  // @@protoc_insertion_point(field_get:cybertx.messages.PPMUpdateAll.line)
  return _internal_line();
}
inline void PPMUpdateAll::_internal_set_line(int32_t value) {
  
  line_ = value;
}
inline void PPMUpdateAll::set_line(int32_t value) {
  _internal_set_line(value);
  // @@protoc_insertion_point(field_set:cybertx.messages.PPMUpdateAll.line)
}

// repeated int32 channel_values = 2;
inline int PPMUpdateAll::_internal_channel_values_size() const {
  return channel_values_.size();
}
inline int PPMUpdateAll::channel_values_size() const {
  return _internal_channel_values_size();
}
inline void PPMUpdateAll::clear_channel_values() {
  channel_values_.Clear();
}
inline int32_t PPMUpdateAll::_internal_channel_values(int index) const {
  return channel_values_.Get(index);
}
inline int32_t PPMUpdateAll::channel_values(int index) const {
  // @@protoc_insertion_point(field_get:cybertx.messages.PPMUpdateAll.channel_values)
  return _internal_channel_values(index);
}
inline void PPMUpdateAll::set_channel_values(int index, int32_t value) {
  channel_values_.Set(index, value);
  // @@protoc_insertion_point(field_set:cybertx.messages.PPMUpdateAll.channel_values)
}
inline void PPMUpdateAll::_internal_add_channel_values(int32_t value) {
  channel_values_.Add(value);
}
inline void PPMUpdateAll::add_channel_values(int32_t value) {
  _internal_add_channel_values(value);
  // @@protoc_insertion_point(field_add:cybertx.messages.PPMUpdateAll.channel_values)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
PPMUpdateAll::_internal_channel_values() const {
  return channel_values_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
PPMUpdateAll::channel_values() const {
  // @@protoc_insertion_point(field_list:cybertx.messages.PPMUpdateAll.channel_values)
  return _internal_channel_values();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
PPMUpdateAll::_internal_mutable_channel_values() {
  return &channel_values_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
PPMUpdateAll::mutable_channel_values() {
  // @@protoc_insertion_point(field_mutable_list:cybertx.messages.PPMUpdateAll.channel_values)
  return _internal_mutable_channel_values();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace messages
}  // namespace cybertx

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_message_2eproto
