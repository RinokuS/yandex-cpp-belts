// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: database.proto

#include "database.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_database_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Buses_database_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_database_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Stops_database_2eproto;
namespace ProtoTransport {
class StopsDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Stops> _instance;
} _Stops_default_instance_;
class BusesDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Buses> _instance;
} _Buses_default_instance_;
class DatabaseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Database> _instance;
} _Database_default_instance_;
}  // namespace ProtoTransport
static void InitDefaultsscc_info_Buses_database_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::ProtoTransport::_Buses_default_instance_;
    new (ptr) ::ProtoTransport::Buses();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ProtoTransport::Buses::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Buses_database_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Buses_database_2eproto}, {}};

static void InitDefaultsscc_info_Database_database_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::ProtoTransport::_Database_default_instance_;
    new (ptr) ::ProtoTransport::Database();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ProtoTransport::Database::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_Database_database_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_Database_database_2eproto}, {
      &scc_info_Stops_database_2eproto.base,
      &scc_info_Buses_database_2eproto.base,}};

static void InitDefaultsscc_info_Stops_database_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::ProtoTransport::_Stops_default_instance_;
    new (ptr) ::ProtoTransport::Stops();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ProtoTransport::Stops::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Stops_database_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Stops_database_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_database_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_database_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_database_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_database_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Stops, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Stops, name_),
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Stops, buses_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Buses, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Buses, name_),
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Buses, stops_),
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Buses, unique_stops_),
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Buses, road_route_),
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Buses, linear_route_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Database, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Database, stops_),
  PROTOBUF_FIELD_OFFSET(::ProtoTransport::Database, buses_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::ProtoTransport::Stops)},
  { 7, -1, sizeof(::ProtoTransport::Buses)},
  { 17, -1, sizeof(::ProtoTransport::Database)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::ProtoTransport::_Stops_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::ProtoTransport::_Buses_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::ProtoTransport::_Database_default_instance_),
};

const char descriptor_table_protodef_database_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016database.proto\022\016ProtoTransport\"$\n\005Stop"
  "s\022\014\n\004name\030\001 \001(\t\022\r\n\005buses\030\002 \003(\t\"d\n\005Buses\022"
  "\014\n\004name\030\001 \001(\t\022\r\n\005stops\030\002 \001(\r\022\024\n\014unique_s"
  "tops\030\003 \001(\r\022\022\n\nroad_route\030\004 \001(\r\022\024\n\014linear"
  "_route\030\005 \001(\001\"V\n\010Database\022$\n\005stops\030\001 \003(\0132"
  "\025.ProtoTransport.Stops\022$\n\005buses\030\002 \003(\0132\025."
  "ProtoTransport.Busesb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_database_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_database_2eproto_sccs[3] = {
  &scc_info_Buses_database_2eproto.base,
  &scc_info_Database_database_2eproto.base,
  &scc_info_Stops_database_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_database_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_database_2eproto = {
  false, false, descriptor_table_protodef_database_2eproto, "database.proto", 268,
  &descriptor_table_database_2eproto_once, descriptor_table_database_2eproto_sccs, descriptor_table_database_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_database_2eproto::offsets,
  file_level_metadata_database_2eproto, 3, file_level_enum_descriptors_database_2eproto, file_level_service_descriptors_database_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_database_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_database_2eproto)), true);
namespace ProtoTransport {

// ===================================================================

void Stops::InitAsDefaultInstance() {
}
class Stops::_Internal {
 public:
};

Stops::Stops(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  buses_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ProtoTransport.Stops)
}
Stops::Stops(const Stops& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      buses_(from.buses_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:ProtoTransport.Stops)
}

void Stops::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Stops_database_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Stops::~Stops() {
  // @@protoc_insertion_point(destructor:ProtoTransport.Stops)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Stops::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Stops::ArenaDtor(void* object) {
  Stops* _this = reinterpret_cast< Stops* >(object);
  (void)_this;
}
void Stops::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Stops::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Stops& Stops::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Stops_database_2eproto.base);
  return *internal_default_instance();
}


void Stops::Clear() {
// @@protoc_insertion_point(message_clear_start:ProtoTransport.Stops)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  buses_.Clear();
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Stops::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ProtoTransport.Stops.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string buses = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_buses();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ProtoTransport.Stops.buses"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Stops::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ProtoTransport.Stops)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ProtoTransport.Stops.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // repeated string buses = 2;
  for (int i = 0, n = this->_internal_buses_size(); i < n; i++) {
    const auto& s = this->_internal_buses(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ProtoTransport.Stops.buses");
    target = stream->WriteString(2, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ProtoTransport.Stops)
  return target;
}

size_t Stops::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ProtoTransport.Stops)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string buses = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(buses_.size());
  for (int i = 0, n = buses_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      buses_.Get(i));
  }

  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Stops::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ProtoTransport.Stops)
  GOOGLE_DCHECK_NE(&from, this);
  const Stops* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Stops>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ProtoTransport.Stops)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ProtoTransport.Stops)
    MergeFrom(*source);
  }
}

void Stops::MergeFrom(const Stops& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ProtoTransport.Stops)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  buses_.MergeFrom(from.buses_);
  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
}

void Stops::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ProtoTransport.Stops)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Stops::CopyFrom(const Stops& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ProtoTransport.Stops)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Stops::IsInitialized() const {
  return true;
}

void Stops::InternalSwap(Stops* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  buses_.InternalSwap(&other->buses_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata Stops::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Buses::InitAsDefaultInstance() {
}
class Buses::_Internal {
 public:
};

Buses::Buses(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ProtoTransport.Buses)
}
Buses::Buses(const Buses& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  ::memcpy(&stops_, &from.stops_,
    static_cast<size_t>(reinterpret_cast<char*>(&road_route_) -
    reinterpret_cast<char*>(&stops_)) + sizeof(road_route_));
  // @@protoc_insertion_point(copy_constructor:ProtoTransport.Buses)
}

void Buses::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Buses_database_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&stops_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&road_route_) -
      reinterpret_cast<char*>(&stops_)) + sizeof(road_route_));
}

Buses::~Buses() {
  // @@protoc_insertion_point(destructor:ProtoTransport.Buses)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Buses::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Buses::ArenaDtor(void* object) {
  Buses* _this = reinterpret_cast< Buses* >(object);
  (void)_this;
}
void Buses::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Buses::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Buses& Buses::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Buses_database_2eproto.base);
  return *internal_default_instance();
}


void Buses::Clear() {
// @@protoc_insertion_point(message_clear_start:ProtoTransport.Buses)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&stops_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&road_route_) -
      reinterpret_cast<char*>(&stops_)) + sizeof(road_route_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Buses::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ProtoTransport.Buses.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 stops = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          stops_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 unique_stops = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          unique_stops_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 road_route = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          road_route_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // double linear_route = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 41)) {
          linear_route_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Buses::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ProtoTransport.Buses)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ProtoTransport.Buses.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // uint32 stops = 2;
  if (this->stops() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_stops(), target);
  }

  // uint32 unique_stops = 3;
  if (this->unique_stops() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_unique_stops(), target);
  }

  // uint32 road_route = 4;
  if (this->road_route() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(4, this->_internal_road_route(), target);
  }

  // double linear_route = 5;
  if (!(this->linear_route() <= 0 && this->linear_route() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(5, this->_internal_linear_route(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ProtoTransport.Buses)
  return target;
}

size_t Buses::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ProtoTransport.Buses)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // uint32 stops = 2;
  if (this->stops() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_stops());
  }

  // uint32 unique_stops = 3;
  if (this->unique_stops() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_unique_stops());
  }

  // double linear_route = 5;
  if (!(this->linear_route() <= 0 && this->linear_route() >= 0)) {
    total_size += 1 + 8;
  }

  // uint32 road_route = 4;
  if (this->road_route() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_road_route());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Buses::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ProtoTransport.Buses)
  GOOGLE_DCHECK_NE(&from, this);
  const Buses* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Buses>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ProtoTransport.Buses)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ProtoTransport.Buses)
    MergeFrom(*source);
  }
}

void Buses::MergeFrom(const Buses& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ProtoTransport.Buses)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.stops() != 0) {
    _internal_set_stops(from._internal_stops());
  }
  if (from.unique_stops() != 0) {
    _internal_set_unique_stops(from._internal_unique_stops());
  }
  if (!(from.linear_route() <= 0 && from.linear_route() >= 0)) {
    _internal_set_linear_route(from._internal_linear_route());
  }
  if (from.road_route() != 0) {
    _internal_set_road_route(from._internal_road_route());
  }
}

void Buses::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ProtoTransport.Buses)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Buses::CopyFrom(const Buses& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ProtoTransport.Buses)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Buses::IsInitialized() const {
  return true;
}

void Buses::InternalSwap(Buses* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Buses, road_route_)
      + sizeof(Buses::road_route_)
      - PROTOBUF_FIELD_OFFSET(Buses, stops_)>(
          reinterpret_cast<char*>(&stops_),
          reinterpret_cast<char*>(&other->stops_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Buses::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Database::InitAsDefaultInstance() {
}
class Database::_Internal {
 public:
};

Database::Database(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  stops_(arena),
  buses_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ProtoTransport.Database)
}
Database::Database(const Database& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      stops_(from.stops_),
      buses_(from.buses_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:ProtoTransport.Database)
}

void Database::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Database_database_2eproto.base);
}

Database::~Database() {
  // @@protoc_insertion_point(destructor:ProtoTransport.Database)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Database::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void Database::ArenaDtor(void* object) {
  Database* _this = reinterpret_cast< Database* >(object);
  (void)_this;
}
void Database::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Database::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Database& Database::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Database_database_2eproto.base);
  return *internal_default_instance();
}


void Database::Clear() {
// @@protoc_insertion_point(message_clear_start:ProtoTransport.Database)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  stops_.Clear();
  buses_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Database::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .ProtoTransport.Stops stops = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_stops(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .ProtoTransport.Buses buses = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_buses(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Database::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ProtoTransport.Database)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .ProtoTransport.Stops stops = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_stops_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_stops(i), target, stream);
  }

  // repeated .ProtoTransport.Buses buses = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_buses_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_buses(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ProtoTransport.Database)
  return target;
}

size_t Database::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ProtoTransport.Database)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .ProtoTransport.Stops stops = 1;
  total_size += 1UL * this->_internal_stops_size();
  for (const auto& msg : this->stops_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .ProtoTransport.Buses buses = 2;
  total_size += 1UL * this->_internal_buses_size();
  for (const auto& msg : this->buses_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Database::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ProtoTransport.Database)
  GOOGLE_DCHECK_NE(&from, this);
  const Database* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Database>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ProtoTransport.Database)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ProtoTransport.Database)
    MergeFrom(*source);
  }
}

void Database::MergeFrom(const Database& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ProtoTransport.Database)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  stops_.MergeFrom(from.stops_);
  buses_.MergeFrom(from.buses_);
}

void Database::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ProtoTransport.Database)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Database::CopyFrom(const Database& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ProtoTransport.Database)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Database::IsInitialized() const {
  return true;
}

void Database::InternalSwap(Database* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  stops_.InternalSwap(&other->stops_);
  buses_.InternalSwap(&other->buses_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Database::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace ProtoTransport
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ProtoTransport::Stops* Arena::CreateMaybeMessage< ::ProtoTransport::Stops >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ProtoTransport::Stops >(arena);
}
template<> PROTOBUF_NOINLINE ::ProtoTransport::Buses* Arena::CreateMaybeMessage< ::ProtoTransport::Buses >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ProtoTransport::Buses >(arena);
}
template<> PROTOBUF_NOINLINE ::ProtoTransport::Database* Arena::CreateMaybeMessage< ::ProtoTransport::Database >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ProtoTransport::Database >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
