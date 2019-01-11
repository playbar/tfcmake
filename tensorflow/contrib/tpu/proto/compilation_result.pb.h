// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/contrib/tpu/proto/compilation_result.proto

#ifndef PROTOBUF_tensorflow_2fcontrib_2ftpu_2fproto_2fcompilation_5fresult_2eproto__INCLUDED
#define PROTOBUF_tensorflow_2fcontrib_2ftpu_2fproto_2fcompilation_5fresult_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "tensorflow/core/lib/core/error_codes.pb.h"
// @@protoc_insertion_point(includes)
namespace tensorflow {
namespace tpu {
class CompilationResultProto;
class CompilationResultProtoDefaultTypeInternal;
extern CompilationResultProtoDefaultTypeInternal _CompilationResultProto_default_instance_;
}  // namespace tpu
}  // namespace tensorflow

namespace tensorflow {
namespace tpu {

namespace protobuf_tensorflow_2fcontrib_2ftpu_2fproto_2fcompilation_5fresult_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_tensorflow_2fcontrib_2ftpu_2fproto_2fcompilation_5fresult_2eproto

// ===================================================================

class CompilationResultProto : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.tpu.CompilationResultProto) */ {
 public:
  CompilationResultProto();
  virtual ~CompilationResultProto();

  CompilationResultProto(const CompilationResultProto& from);

  inline CompilationResultProto& operator=(const CompilationResultProto& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CompilationResultProto(CompilationResultProto&& from) noexcept
    : CompilationResultProto() {
    *this = ::std::move(from);
  }

  inline CompilationResultProto& operator=(CompilationResultProto&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline ::google::protobuf::Arena* GetArena() const PROTOBUF_FINAL {
    return GetArenaNoVirtual();
  }
  inline void* GetMaybeArenaPointer() const PROTOBUF_FINAL {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const CompilationResultProto& default_instance();

  static inline const CompilationResultProto* internal_default_instance() {
    return reinterpret_cast<const CompilationResultProto*>(
               &_CompilationResultProto_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void UnsafeArenaSwap(CompilationResultProto* other);
  void Swap(CompilationResultProto* other);
  friend void swap(CompilationResultProto& a, CompilationResultProto& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CompilationResultProto* New() const PROTOBUF_FINAL { return New(NULL); }

  CompilationResultProto* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CompilationResultProto& from);
  void MergeFrom(const CompilationResultProto& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CompilationResultProto* other);
  protected:
  explicit CompilationResultProto(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string status_error_message = 2;
  void clear_status_error_message();
  static const int kStatusErrorMessageFieldNumber = 2;
  const ::std::string& status_error_message() const;
  void set_status_error_message(const ::std::string& value);
  #if LANG_CXX11
  void set_status_error_message(::std::string&& value);
  #endif
  void set_status_error_message(const char* value);
  void set_status_error_message(const char* value, size_t size);
  ::std::string* mutable_status_error_message();
  ::std::string* release_status_error_message();
  void set_allocated_status_error_message(::std::string* status_error_message);
  ::std::string* unsafe_arena_release_status_error_message();
  void unsafe_arena_set_allocated_status_error_message(
      ::std::string* status_error_message);

  // .tensorflow.error.Code status_code = 1;
  void clear_status_code();
  static const int kStatusCodeFieldNumber = 1;
  ::tensorflow::error::Code status_code() const;
  void set_status_code(::tensorflow::error::Code value);

  // @@protoc_insertion_point(class_scope:tensorflow.tpu.CompilationResultProto)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::google::protobuf::internal::ArenaStringPtr status_error_message_;
  int status_code_;
  mutable int _cached_size_;
  friend struct protobuf_tensorflow_2fcontrib_2ftpu_2fproto_2fcompilation_5fresult_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CompilationResultProto

// .tensorflow.error.Code status_code = 1;
inline void CompilationResultProto::clear_status_code() {
  status_code_ = 0;
}
inline ::tensorflow::error::Code CompilationResultProto::status_code() const {
  // @@protoc_insertion_point(field_get:tensorflow.tpu.CompilationResultProto.status_code)
  return static_cast< ::tensorflow::error::Code >(status_code_);
}
inline void CompilationResultProto::set_status_code(::tensorflow::error::Code value) {
  
  status_code_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.tpu.CompilationResultProto.status_code)
}

// string status_error_message = 2;
inline void CompilationResultProto::clear_status_error_message() {
  status_error_message_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& CompilationResultProto::status_error_message() const {
  // @@protoc_insertion_point(field_get:tensorflow.tpu.CompilationResultProto.status_error_message)
  return status_error_message_.Get();
}
inline void CompilationResultProto::set_status_error_message(const ::std::string& value) {
  
  status_error_message_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.tpu.CompilationResultProto.status_error_message)
}
#if LANG_CXX11
inline void CompilationResultProto::set_status_error_message(::std::string&& value) {
  
  status_error_message_.Set(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_rvalue:tensorflow.tpu.CompilationResultProto.status_error_message)
}
#endif
inline void CompilationResultProto::set_status_error_message(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  status_error_message_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.tpu.CompilationResultProto.status_error_message)
}
inline void CompilationResultProto::set_status_error_message(const char* value,
    size_t size) {
  
  status_error_message_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.tpu.CompilationResultProto.status_error_message)
}
inline ::std::string* CompilationResultProto::mutable_status_error_message() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.tpu.CompilationResultProto.status_error_message)
  return status_error_message_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* CompilationResultProto::release_status_error_message() {
  // @@protoc_insertion_point(field_release:tensorflow.tpu.CompilationResultProto.status_error_message)
  
  return status_error_message_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* CompilationResultProto::unsafe_arena_release_status_error_message() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.tpu.CompilationResultProto.status_error_message)
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  
  return status_error_message_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void CompilationResultProto::set_allocated_status_error_message(::std::string* status_error_message) {
  if (status_error_message != NULL) {
    
  } else {
    
  }
  status_error_message_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), status_error_message,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.tpu.CompilationResultProto.status_error_message)
}
inline void CompilationResultProto::unsafe_arena_set_allocated_status_error_message(
    ::std::string* status_error_message) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  if (status_error_message != NULL) {
    
  } else {
    
  }
  status_error_message_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      status_error_message, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.tpu.CompilationResultProto.status_error_message)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace tpu
}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_tensorflow_2fcontrib_2ftpu_2fproto_2fcompilation_5fresult_2eproto__INCLUDED
