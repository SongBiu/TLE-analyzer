; ModuleID = 'functionLibs.cpp'
source_filename = "functionLibs.cpp"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.14.0"

%"class.std::__1::basic_ostream" = type { i32 (...)**, %"class.std::__1::basic_ios.base" }
%"class.std::__1::basic_ios.base" = type <{ %"class.std::__1::ios_base", %"class.std::__1::basic_ostream"*, i32 }>
%"class.std::__1::ios_base" = type { i32 (...)**, i32, i64, i64, i32, i32, i8*, i8*, void (i32, %"class.std::__1::ios_base"*, i32)**, i32*, i64, i64, i64*, i64, i64, i8**, i64, i64 }
%"class.std::__1::locale::id" = type <{ %"struct.std::__1::once_flag", i32, [4 x i8] }>
%"struct.std::__1::once_flag" = type { i64 }
%"class.std::__1::ctype" = type <{ %"class.std::__1::locale::facet", i32*, i8, [7 x i8] }>
%"class.std::__1::locale::facet" = type { %"class.std::__1::__shared_count" }
%"class.std::__1::__shared_count" = type { i32 (...)**, i64 }
%"class.std::__1::locale" = type { %"class.std::__1::locale::__imp"* }
%"class.std::__1::locale::__imp" = type opaque
%"class.std::__1::basic_ios" = type <{ %"class.std::__1::ios_base", %"class.std::__1::basic_ostream"*, i32, [4 x i8] }>
%"class.std::__1::ostreambuf_iterator" = type { %"class.std::__1::basic_streambuf"* }
%"class.std::__1::basic_streambuf" = type { i32 (...)**, %"class.std::__1::locale", i8*, i8*, i8*, i8*, i8*, i8* }
%"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry" = type { i8, %"class.std::__1::basic_ostream"* }
%"struct.std::__1::iterator" = type { i8 }
%"struct.std::__1::__compressed_pair_elem" = type { %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep" }
%"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep" = type { %union.anon }
%union.anon = type { %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long" }
%"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long" = type { i64, i64, i8* }
%"class.std::__1::__compressed_pair" = type { %"struct.std::__1::__compressed_pair_elem" }
%"class.std::__1::basic_string" = type { %"class.std::__1::__compressed_pair" }
%"class.std::__1::allocator" = type { i8 }
%"struct.std::__1::__compressed_pair_elem.1" = type { i8 }
%"class.std::__1::__basic_string_common" = type { i8 }
%"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short" = type { %union.anon.0, [23 x i8] }
%union.anon.0 = type { i8 }

@_ZNSt3__14coutE = external global %"class.std::__1::basic_ostream", align 8
@.str = private unnamed_addr constant [20 x i8] c"function is called\0A\00", align 1
@_ZNSt3__15ctypeIcE2idE = external global %"class.std::__1::locale::id", align 8

; Function Attrs: noinline optnone ssp uwtable
define void @_Z4demov() #0 {
  %1 = call dereferenceable(160) %"class.std::__1::basic_ostream"* @_ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc(%"class.std::__1::basic_ostream"* dereferenceable(160) @_ZNSt3__14coutE, i8* getelementptr inbounds ([20 x i8], [20 x i8]* @.str, i32 0, i32 0))
  ret void
}

; Function Attrs: noinline optnone ssp uwtable
define linkonce_odr dereferenceable(160) %"class.std::__1::basic_ostream"* @_ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc(%"class.std::__1::basic_ostream"* dereferenceable(160), i8*) #0 {
  %3 = alloca %"class.std::__1::basic_ostream"*, align 8
  %4 = alloca i8*, align 8
  store %"class.std::__1::basic_ostream"* %0, %"class.std::__1::basic_ostream"** %3, align 8
  store i8* %1, i8** %4, align 8
  %5 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %3, align 8
  %6 = load i8*, i8** %4, align 8
  %7 = load i8*, i8** %4, align 8
  %8 = call i64 @_ZNSt3__111char_traitsIcE6lengthEPKc(i8* %7) #6
  %9 = call dereferenceable(160) %"class.std::__1::basic_ostream"* @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__1::basic_ostream"* dereferenceable(160) %5, i8* %6, i64 %8)
  ret %"class.std::__1::basic_ostream"* %9
}

; Function Attrs: noinline optnone ssp uwtable
define linkonce_odr dereferenceable(160) %"class.std::__1::basic_ostream"* @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__1::basic_ostream"* dereferenceable(160), i8*, i64) #0 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %4 = alloca %"class.std::__1::ctype"*, align 8
  %5 = alloca i8, align 1
  %6 = alloca %"class.std::__1::locale"*, align 8
  %7 = alloca %"class.std::__1::basic_ios"*, align 8
  %8 = alloca i8, align 1
  %9 = alloca %"class.std::__1::locale", align 8
  %10 = alloca i8*
  %11 = alloca i32
  %12 = alloca %"class.std::__1::basic_ios"*, align 8
  %13 = alloca %"class.std::__1::ostreambuf_iterator"*, align 8
  %14 = alloca %"class.std::__1::ios_base"*, align 8
  %15 = alloca %"class.std::__1::ios_base"*, align 8
  %16 = alloca i32, align 4
  %17 = alloca %"class.std::__1::basic_ios"*, align 8
  %18 = alloca i32, align 4
  %19 = alloca %"class.std::__1::ios_base"*, align 8
  %20 = alloca %"class.std::__1::basic_ios"*, align 8
  %21 = alloca %"class.std::__1::ostreambuf_iterator"*, align 8
  %22 = alloca %"class.std::__1::basic_ostream"*, align 8
  %23 = alloca %"class.std::__1::ostreambuf_iterator"*, align 8
  %24 = alloca %"class.std::__1::basic_ostream"*, align 8
  %25 = alloca %"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"*, align 8
  %26 = alloca %"class.std::__1::basic_ostream"*, align 8
  %27 = alloca i8*, align 8
  %28 = alloca i64, align 8
  %29 = alloca %"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry", align 8
  %30 = alloca i8*
  %31 = alloca i32
  %32 = alloca %"class.std::__1::ostreambuf_iterator", align 8
  %33 = alloca %"class.std::__1::ostreambuf_iterator", align 8
  store %"class.std::__1::basic_ostream"* %0, %"class.std::__1::basic_ostream"** %26, align 8
  store i8* %1, i8** %27, align 8
  store i64 %2, i64* %28, align 8
  %34 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %26, align 8
  invoke void @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_(%"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"* %29, %"class.std::__1::basic_ostream"* dereferenceable(160) %34)
          to label %35 unwind label %174

; <label>:35:                                     ; preds = %3
  store %"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"* %29, %"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"** %25, align 8
  %36 = load %"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"*, %"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"** %25, align 8
  %37 = getelementptr inbounds %"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry", %"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"* %36, i32 0, i32 0
  %38 = load i8, i8* %37, align 8
  %39 = trunc i8 %38 to i1
  br label %40

; <label>:40:                                     ; preds = %35
  br i1 %39, label %41, label %200

; <label>:41:                                     ; preds = %40
  %42 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %26, align 8
  store %"class.std::__1::ostreambuf_iterator"* %33, %"class.std::__1::ostreambuf_iterator"** %23, align 8
  store %"class.std::__1::basic_ostream"* %42, %"class.std::__1::basic_ostream"** %24, align 8
  %43 = load %"class.std::__1::ostreambuf_iterator"*, %"class.std::__1::ostreambuf_iterator"** %23, align 8
  %44 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %24, align 8
  store %"class.std::__1::ostreambuf_iterator"* %43, %"class.std::__1::ostreambuf_iterator"** %21, align 8
  store %"class.std::__1::basic_ostream"* %44, %"class.std::__1::basic_ostream"** %22, align 8
  %45 = load %"class.std::__1::ostreambuf_iterator"*, %"class.std::__1::ostreambuf_iterator"** %21, align 8
  %46 = bitcast %"class.std::__1::ostreambuf_iterator"* %45 to %"struct.std::__1::iterator"*
  %47 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %45, i32 0, i32 0
  %48 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %22, align 8
  %49 = bitcast %"class.std::__1::basic_ostream"* %48 to i8**
  %50 = load i8*, i8** %49, align 8
  %51 = getelementptr i8, i8* %50, i64 -24
  %52 = bitcast i8* %51 to i64*
  %53 = load i64, i64* %52, align 8
  %54 = bitcast %"class.std::__1::basic_ostream"* %48 to i8*
  %55 = getelementptr inbounds i8, i8* %54, i64 %53
  %56 = bitcast i8* %55 to %"class.std::__1::basic_ios"*
  store %"class.std::__1::basic_ios"* %56, %"class.std::__1::basic_ios"** %20, align 8
  %57 = load %"class.std::__1::basic_ios"*, %"class.std::__1::basic_ios"** %20, align 8
  %58 = bitcast %"class.std::__1::basic_ios"* %57 to %"class.std::__1::ios_base"*
  store %"class.std::__1::ios_base"* %58, %"class.std::__1::ios_base"** %19, align 8
  %59 = load %"class.std::__1::ios_base"*, %"class.std::__1::ios_base"** %19, align 8
  %60 = getelementptr inbounds %"class.std::__1::ios_base", %"class.std::__1::ios_base"* %59, i32 0, i32 6
  %61 = load i8*, i8** %60, align 8
  %62 = bitcast i8* %61 to %"class.std::__1::basic_streambuf"*
  store %"class.std::__1::basic_streambuf"* %62, %"class.std::__1::basic_streambuf"** %47, align 8
  %63 = load i8*, i8** %27, align 8
  %64 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %26, align 8
  %65 = bitcast %"class.std::__1::basic_ostream"* %64 to i8**
  %66 = load i8*, i8** %65, align 8
  %67 = getelementptr i8, i8* %66, i64 -24
  %68 = bitcast i8* %67 to i64*
  %69 = load i64, i64* %68, align 8
  %70 = bitcast %"class.std::__1::basic_ostream"* %64 to i8*
  %71 = getelementptr inbounds i8, i8* %70, i64 %69
  %72 = bitcast i8* %71 to %"class.std::__1::ios_base"*
  store %"class.std::__1::ios_base"* %72, %"class.std::__1::ios_base"** %14, align 8
  %73 = load %"class.std::__1::ios_base"*, %"class.std::__1::ios_base"** %14, align 8
  %74 = getelementptr inbounds %"class.std::__1::ios_base", %"class.std::__1::ios_base"* %73, i32 0, i32 1
  %75 = load i32, i32* %74, align 8
  br label %76

; <label>:76:                                     ; preds = %41
  %77 = and i32 %75, 176
  %78 = icmp eq i32 %77, 32
  br i1 %78, label %79, label %83

; <label>:79:                                     ; preds = %76
  %80 = load i8*, i8** %27, align 8
  %81 = load i64, i64* %28, align 8
  %82 = getelementptr inbounds i8, i8* %80, i64 %81
  br label %85

; <label>:83:                                     ; preds = %76
  %84 = load i8*, i8** %27, align 8
  br label %85

; <label>:85:                                     ; preds = %83, %79
  %86 = phi i8* [ %82, %79 ], [ %84, %83 ]
  %87 = load i8*, i8** %27, align 8
  %88 = load i64, i64* %28, align 8
  %89 = getelementptr inbounds i8, i8* %87, i64 %88
  %90 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %26, align 8
  %91 = bitcast %"class.std::__1::basic_ostream"* %90 to i8**
  %92 = load i8*, i8** %91, align 8
  %93 = getelementptr i8, i8* %92, i64 -24
  %94 = bitcast i8* %93 to i64*
  %95 = load i64, i64* %94, align 8
  %96 = bitcast %"class.std::__1::basic_ostream"* %90 to i8*
  %97 = getelementptr inbounds i8, i8* %96, i64 %95
  %98 = bitcast i8* %97 to %"class.std::__1::ios_base"*
  %99 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %26, align 8
  %100 = bitcast %"class.std::__1::basic_ostream"* %99 to i8**
  %101 = load i8*, i8** %100, align 8
  %102 = getelementptr i8, i8* %101, i64 -24
  %103 = bitcast i8* %102 to i64*
  %104 = load i64, i64* %103, align 8
  %105 = bitcast %"class.std::__1::basic_ostream"* %99 to i8*
  %106 = getelementptr inbounds i8, i8* %105, i64 %104
  %107 = bitcast i8* %106 to %"class.std::__1::basic_ios"*
  store %"class.std::__1::basic_ios"* %107, %"class.std::__1::basic_ios"** %12, align 8
  %108 = load %"class.std::__1::basic_ios"*, %"class.std::__1::basic_ios"** %12, align 8
  %109 = call i32 @_ZNSt3__111char_traitsIcE3eofEv() #6
  %110 = getelementptr inbounds %"class.std::__1::basic_ios", %"class.std::__1::basic_ios"* %108, i32 0, i32 2
  %111 = load i32, i32* %110, align 8
  %112 = call zeroext i1 @_ZNSt3__111char_traitsIcE11eq_int_typeEii(i32 %109, i32 %111) #6
  br i1 %112, label %113, label %140

; <label>:113:                                    ; preds = %85
  store %"class.std::__1::basic_ios"* %108, %"class.std::__1::basic_ios"** %7, align 8
  store i8 32, i8* %8, align 1
  %114 = load %"class.std::__1::basic_ios"*, %"class.std::__1::basic_ios"** %7, align 8
  %115 = bitcast %"class.std::__1::basic_ios"* %114 to %"class.std::__1::ios_base"*
  invoke void @_ZNKSt3__18ios_base6getlocEv(%"class.std::__1::locale"* sret %9, %"class.std::__1::ios_base"* %115)
          to label %116 unwind label %178

; <label>:116:                                    ; preds = %113
  store %"class.std::__1::locale"* %9, %"class.std::__1::locale"** %6, align 8
  %117 = load %"class.std::__1::locale"*, %"class.std::__1::locale"** %6, align 8
  %118 = invoke %"class.std::__1::locale::facet"* @_ZNKSt3__16locale9use_facetERNS0_2idE(%"class.std::__1::locale"* %117, %"class.std::__1::locale::id"* dereferenceable(16) @_ZNSt3__15ctypeIcE2idE)
          to label %119 unwind label %129

; <label>:119:                                    ; preds = %116
  %120 = bitcast %"class.std::__1::locale::facet"* %118 to %"class.std::__1::ctype"*
  %121 = load i8, i8* %8, align 1
  store %"class.std::__1::ctype"* %120, %"class.std::__1::ctype"** %4, align 8
  store i8 %121, i8* %5, align 1
  %122 = load %"class.std::__1::ctype"*, %"class.std::__1::ctype"** %4, align 8
  %123 = load i8, i8* %5, align 1
  %124 = bitcast %"class.std::__1::ctype"* %122 to i8 (%"class.std::__1::ctype"*, i8)***
  %125 = load i8 (%"class.std::__1::ctype"*, i8)**, i8 (%"class.std::__1::ctype"*, i8)*** %124, align 8
  %126 = getelementptr inbounds i8 (%"class.std::__1::ctype"*, i8)*, i8 (%"class.std::__1::ctype"*, i8)** %125, i64 7
  %127 = load i8 (%"class.std::__1::ctype"*, i8)*, i8 (%"class.std::__1::ctype"*, i8)** %126, align 8
  %128 = invoke signext i8 %127(%"class.std::__1::ctype"* %122, i8 signext %123)
          to label %137 unwind label %129

; <label>:129:                                    ; preds = %119, %116
  %130 = landingpad { i8*, i32 }
          cleanup
          catch i8* null
  %131 = extractvalue { i8*, i32 } %130, 0
  store i8* %131, i8** %10, align 8
  %132 = extractvalue { i8*, i32 } %130, 1
  store i32 %132, i32* %11, align 4
  call void @_ZNSt3__16localeD1Ev(%"class.std::__1::locale"* %9) #6
  %133 = load i8*, i8** %10, align 8
  %134 = load i32, i32* %11, align 4
  %135 = insertvalue { i8*, i32 } undef, i8* %133, 0
  %136 = insertvalue { i8*, i32 } %135, i32 %134, 1
  br label %180

; <label>:137:                                    ; preds = %119
  call void @_ZNSt3__16localeD1Ev(%"class.std::__1::locale"* %9) #6
  %138 = sext i8 %128 to i32
  %139 = getelementptr inbounds %"class.std::__1::basic_ios", %"class.std::__1::basic_ios"* %108, i32 0, i32 2
  store i32 %138, i32* %139, align 8
  br label %140

; <label>:140:                                    ; preds = %85, %137
  %141 = getelementptr inbounds %"class.std::__1::basic_ios", %"class.std::__1::basic_ios"* %108, i32 0, i32 2
  %142 = load i32, i32* %141, align 8
  %143 = trunc i32 %142 to i8
  br label %144

; <label>:144:                                    ; preds = %140
  %145 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %33, i32 0, i32 0
  %146 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %145, align 8
  %147 = invoke %"class.std::__1::basic_streambuf"* @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_(%"class.std::__1::basic_streambuf"* %146, i8* %63, i8* %86, i8* %89, %"class.std::__1::ios_base"* dereferenceable(136) %98, i8 signext %143)
          to label %148 unwind label %178

; <label>:148:                                    ; preds = %144
  %149 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %32, i32 0, i32 0
  store %"class.std::__1::basic_streambuf"* %147, %"class.std::__1::basic_streambuf"** %149, align 8
  store %"class.std::__1::ostreambuf_iterator"* %32, %"class.std::__1::ostreambuf_iterator"** %13, align 8
  %150 = load %"class.std::__1::ostreambuf_iterator"*, %"class.std::__1::ostreambuf_iterator"** %13, align 8
  %151 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %150, i32 0, i32 0
  %152 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %151, align 8
  %153 = icmp eq %"class.std::__1::basic_streambuf"* %152, null
  br i1 %153, label %154, label %199

; <label>:154:                                    ; preds = %148
  %155 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %26, align 8
  %156 = bitcast %"class.std::__1::basic_ostream"* %155 to i8**
  %157 = load i8*, i8** %156, align 8
  %158 = getelementptr i8, i8* %157, i64 -24
  %159 = bitcast i8* %158 to i64*
  %160 = load i64, i64* %159, align 8
  %161 = bitcast %"class.std::__1::basic_ostream"* %155 to i8*
  %162 = getelementptr inbounds i8, i8* %161, i64 %160
  %163 = bitcast i8* %162 to %"class.std::__1::basic_ios"*
  store %"class.std::__1::basic_ios"* %163, %"class.std::__1::basic_ios"** %17, align 8
  store i32 5, i32* %18, align 4
  %164 = load %"class.std::__1::basic_ios"*, %"class.std::__1::basic_ios"** %17, align 8
  %165 = bitcast %"class.std::__1::basic_ios"* %164 to %"class.std::__1::ios_base"*
  %166 = load i32, i32* %18, align 4
  store %"class.std::__1::ios_base"* %165, %"class.std::__1::ios_base"** %15, align 8
  store i32 %166, i32* %16, align 4
  %167 = load %"class.std::__1::ios_base"*, %"class.std::__1::ios_base"** %15, align 8
  %168 = getelementptr inbounds %"class.std::__1::ios_base", %"class.std::__1::ios_base"* %167, i32 0, i32 4
  %169 = load i32, i32* %168, align 8
  %170 = load i32, i32* %16, align 4
  %171 = or i32 %169, %170
  invoke void @_ZNSt3__18ios_base5clearEj(%"class.std::__1::ios_base"* %167, i32 %171)
          to label %172 unwind label %178

; <label>:172:                                    ; preds = %154
  br label %173

; <label>:173:                                    ; preds = %172
  br label %199

; <label>:174:                                    ; preds = %3
  %175 = landingpad { i8*, i32 }
          catch i8* null
  %176 = extractvalue { i8*, i32 } %175, 0
  store i8* %176, i8** %30, align 8
  %177 = extractvalue { i8*, i32 } %175, 1
  store i32 %177, i32* %31, align 4
  br label %184

; <label>:178:                                    ; preds = %113, %154, %144
  %179 = landingpad { i8*, i32 }
          catch i8* null
  br label %180

; <label>:180:                                    ; preds = %129, %178
  %181 = phi { i8*, i32 } [ %179, %178 ], [ %136, %129 ]
  %182 = extractvalue { i8*, i32 } %181, 0
  store i8* %182, i8** %30, align 8
  %183 = extractvalue { i8*, i32 } %181, 1
  store i32 %183, i32* %31, align 4
  call void @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev(%"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"* %29) #6
  br label %184

; <label>:184:                                    ; preds = %180, %174
  %185 = load i8*, i8** %30, align 8
  %186 = call i8* @__cxa_begin_catch(i8* %185) #6
  %187 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %26, align 8
  %188 = bitcast %"class.std::__1::basic_ostream"* %187 to i8**
  %189 = load i8*, i8** %188, align 8
  %190 = getelementptr i8, i8* %189, i64 -24
  %191 = bitcast i8* %190 to i64*
  %192 = load i64, i64* %191, align 8
  %193 = bitcast %"class.std::__1::basic_ostream"* %187 to i8*
  %194 = getelementptr inbounds i8, i8* %193, i64 %192
  %195 = bitcast i8* %194 to %"class.std::__1::ios_base"*
  invoke void @_ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__1::ios_base"* %195)
          to label %196 unwind label %201

; <label>:196:                                    ; preds = %184
  call void @__cxa_end_catch()
  br label %197

; <label>:197:                                    ; preds = %196, %200
  %198 = load %"class.std::__1::basic_ostream"*, %"class.std::__1::basic_ostream"** %26, align 8
  ret %"class.std::__1::basic_ostream"* %198

; <label>:199:                                    ; preds = %173, %148
  br label %200

; <label>:200:                                    ; preds = %199, %40
  call void @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev(%"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"* %29) #6
  br label %197

; <label>:201:                                    ; preds = %184
  %202 = landingpad { i8*, i32 }
          cleanup
  %203 = extractvalue { i8*, i32 } %202, 0
  store i8* %203, i8** %30, align 8
  %204 = extractvalue { i8*, i32 } %202, 1
  store i32 %204, i32* %31, align 4
  invoke void @__cxa_end_catch()
          to label %205 unwind label %211

; <label>:205:                                    ; preds = %201
  br label %206

; <label>:206:                                    ; preds = %205
  %207 = load i8*, i8** %30, align 8
  %208 = load i32, i32* %31, align 4
  %209 = insertvalue { i8*, i32 } undef, i8* %207, 0
  %210 = insertvalue { i8*, i32 } %209, i32 %208, 1
  resume { i8*, i32 } %210

; <label>:211:                                    ; preds = %201
  %212 = landingpad { i8*, i32 }
          catch i8* null
  %213 = extractvalue { i8*, i32 } %212, 0
  call void @__clang_call_terminate(i8* %213) #7
  unreachable
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define linkonce_odr i64 @_ZNSt3__111char_traitsIcE6lengthEPKc(i8*) #1 align 2 {
  %2 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %3 = load i8*, i8** %2, align 8
  %4 = call i64 @strlen(i8* %3) #6
  ret i64 %4
}

declare void @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_(%"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"*, %"class.std::__1::basic_ostream"* dereferenceable(160)) unnamed_addr #2

declare i32 @__gxx_personality_v0(...)

; Function Attrs: noinline optnone ssp uwtable
define linkonce_odr hidden %"class.std::__1::basic_streambuf"* @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_(%"class.std::__1::basic_streambuf"*, i8*, i8*, i8*, %"class.std::__1::ios_base"* dereferenceable(136), i8 signext) #0 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %7 = alloca %"class.std::__1::basic_streambuf"*, align 8
  %8 = alloca i8*, align 8
  %9 = alloca i64, align 8
  %10 = alloca i8*, align 8
  %11 = alloca %"struct.std::__1::__compressed_pair_elem"*, align 8
  %12 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %13 = alloca %"class.std::__1::basic_string"*, align 8
  %14 = alloca i8*, align 8
  %15 = alloca i8*, align 8
  %16 = alloca %"struct.std::__1::__compressed_pair_elem"*, align 8
  %17 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %18 = alloca %"class.std::__1::basic_string"*, align 8
  %19 = alloca %"struct.std::__1::__compressed_pair_elem"*, align 8
  %20 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %21 = alloca %"class.std::__1::basic_string"*, align 8
  %22 = alloca %"class.std::__1::basic_string"*, align 8
  %23 = alloca %"class.std::__1::basic_string"*, align 8
  %24 = alloca %"class.std::__1::allocator"*, align 8
  %25 = alloca %"struct.std::__1::__compressed_pair_elem.1"*, align 8
  %26 = alloca %"struct.std::__1::__compressed_pair_elem"*, align 8
  %27 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %28 = alloca %"class.std::__1::__compressed_pair"*, align 8
  %29 = alloca %"class.std::__1::basic_string"*, align 8
  %30 = alloca i64, align 8
  %31 = alloca i8, align 1
  %32 = alloca %"class.std::__1::basic_string"*, align 8
  %33 = alloca i64, align 8
  %34 = alloca i8, align 1
  %35 = alloca %"class.std::__1::basic_streambuf"*, align 8
  %36 = alloca i8*, align 8
  %37 = alloca i64, align 8
  %38 = alloca %"class.std::__1::basic_streambuf"*, align 8
  %39 = alloca i8*, align 8
  %40 = alloca i64, align 8
  %41 = alloca %"class.std::__1::ios_base"*, align 8
  %42 = alloca i64, align 8
  %43 = alloca i64, align 8
  %44 = alloca %"class.std::__1::ios_base"*, align 8
  %45 = alloca %"class.std::__1::ostreambuf_iterator", align 8
  %46 = alloca %"class.std::__1::ostreambuf_iterator", align 8
  %47 = alloca i8*, align 8
  %48 = alloca i8*, align 8
  %49 = alloca i8*, align 8
  %50 = alloca %"class.std::__1::ios_base"*, align 8
  %51 = alloca i8, align 1
  %52 = alloca i64, align 8
  %53 = alloca i64, align 8
  %54 = alloca i64, align 8
  %55 = alloca %"class.std::__1::basic_string", align 8
  %56 = alloca i8*
  %57 = alloca i32
  %58 = alloca i32, align 4
  %59 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %46, i32 0, i32 0
  store %"class.std::__1::basic_streambuf"* %0, %"class.std::__1::basic_streambuf"** %59, align 8
  store i8* %1, i8** %47, align 8
  store i8* %2, i8** %48, align 8
  store i8* %3, i8** %49, align 8
  store %"class.std::__1::ios_base"* %4, %"class.std::__1::ios_base"** %50, align 8
  store i8 %5, i8* %51, align 1
  %60 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %46, i32 0, i32 0
  %61 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %60, align 8
  %62 = icmp eq %"class.std::__1::basic_streambuf"* %61, null
  br i1 %62, label %63, label %66

; <label>:63:                                     ; preds = %6
  %64 = bitcast %"class.std::__1::ostreambuf_iterator"* %45 to i8*
  %65 = bitcast %"class.std::__1::ostreambuf_iterator"* %46 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %64, i8* align 8 %65, i64 8, i1 false)
  br label %244

; <label>:66:                                     ; preds = %6
  %67 = load i8*, i8** %49, align 8
  %68 = load i8*, i8** %47, align 8
  %69 = ptrtoint i8* %67 to i64
  %70 = ptrtoint i8* %68 to i64
  %71 = sub i64 %69, %70
  store i64 %71, i64* %52, align 8
  %72 = load %"class.std::__1::ios_base"*, %"class.std::__1::ios_base"** %50, align 8
  store %"class.std::__1::ios_base"* %72, %"class.std::__1::ios_base"** %44, align 8
  %73 = load %"class.std::__1::ios_base"*, %"class.std::__1::ios_base"** %44, align 8
  %74 = getelementptr inbounds %"class.std::__1::ios_base", %"class.std::__1::ios_base"* %73, i32 0, i32 3
  %75 = load i64, i64* %74, align 8
  store i64 %75, i64* %53, align 8
  %76 = load i64, i64* %53, align 8
  %77 = load i64, i64* %52, align 8
  %78 = icmp sgt i64 %76, %77
  br i1 %78, label %79, label %83

; <label>:79:                                     ; preds = %66
  %80 = load i64, i64* %52, align 8
  %81 = load i64, i64* %53, align 8
  %82 = sub nsw i64 %81, %80
  store i64 %82, i64* %53, align 8
  br label %84

; <label>:83:                                     ; preds = %66
  store i64 0, i64* %53, align 8
  br label %84

; <label>:84:                                     ; preds = %83, %79
  %85 = load i8*, i8** %48, align 8
  %86 = load i8*, i8** %47, align 8
  %87 = ptrtoint i8* %85 to i64
  %88 = ptrtoint i8* %86 to i64
  %89 = sub i64 %87, %88
  store i64 %89, i64* %54, align 8
  %90 = load i64, i64* %54, align 8
  %91 = icmp sgt i64 %90, 0
  br i1 %91, label %92, label %112

; <label>:92:                                     ; preds = %84
  %93 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %46, i32 0, i32 0
  %94 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %93, align 8
  %95 = load i8*, i8** %47, align 8
  %96 = load i64, i64* %54, align 8
  store %"class.std::__1::basic_streambuf"* %94, %"class.std::__1::basic_streambuf"** %35, align 8
  store i8* %95, i8** %36, align 8
  store i64 %96, i64* %37, align 8
  %97 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %35, align 8
  %98 = load i8*, i8** %36, align 8
  %99 = load i64, i64* %37, align 8
  %100 = bitcast %"class.std::__1::basic_streambuf"* %97 to i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)***
  %101 = load i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)**, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*** %100, align 8
  %102 = getelementptr inbounds i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)** %101, i64 12
  %103 = load i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)** %102, align 8
  %104 = call i64 %103(%"class.std::__1::basic_streambuf"* %97, i8* %98, i64 %99)
  %105 = load i64, i64* %54, align 8
  %106 = icmp ne i64 %104, %105
  br i1 %106, label %107, label %111

; <label>:107:                                    ; preds = %92
  %108 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %46, i32 0, i32 0
  store %"class.std::__1::basic_streambuf"* null, %"class.std::__1::basic_streambuf"** %108, align 8
  %109 = bitcast %"class.std::__1::ostreambuf_iterator"* %45 to i8*
  %110 = bitcast %"class.std::__1::ostreambuf_iterator"* %46 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %109, i8* align 8 %110, i64 8, i1 false)
  br label %244

; <label>:111:                                    ; preds = %92
  br label %112

; <label>:112:                                    ; preds = %111, %84
  %113 = load i64, i64* %53, align 8
  %114 = icmp sgt i64 %113, 0
  br i1 %114, label %115, label %206

; <label>:115:                                    ; preds = %112
  %116 = load i64, i64* %53, align 8
  %117 = load i8, i8* %51, align 1
  store %"class.std::__1::basic_string"* %55, %"class.std::__1::basic_string"** %32, align 8
  store i64 %116, i64* %33, align 8
  store i8 %117, i8* %34, align 1
  %118 = load %"class.std::__1::basic_string"*, %"class.std::__1::basic_string"** %32, align 8
  %119 = load i64, i64* %33, align 8
  %120 = load i8, i8* %34, align 1
  store %"class.std::__1::basic_string"* %118, %"class.std::__1::basic_string"** %29, align 8
  store i64 %119, i64* %30, align 8
  store i8 %120, i8* %31, align 1
  %121 = load %"class.std::__1::basic_string"*, %"class.std::__1::basic_string"** %29, align 8
  %122 = bitcast %"class.std::__1::basic_string"* %121 to %"class.std::__1::__basic_string_common"*
  %123 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %121, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %123, %"class.std::__1::__compressed_pair"** %28, align 8
  %124 = load %"class.std::__1::__compressed_pair"*, %"class.std::__1::__compressed_pair"** %28, align 8
  store %"class.std::__1::__compressed_pair"* %124, %"class.std::__1::__compressed_pair"** %27, align 8
  %125 = load %"class.std::__1::__compressed_pair"*, %"class.std::__1::__compressed_pair"** %27, align 8
  %126 = bitcast %"class.std::__1::__compressed_pair"* %125 to %"struct.std::__1::__compressed_pair_elem"*
  store %"struct.std::__1::__compressed_pair_elem"* %126, %"struct.std::__1::__compressed_pair_elem"** %26, align 8
  %127 = load %"struct.std::__1::__compressed_pair_elem"*, %"struct.std::__1::__compressed_pair_elem"** %26, align 8
  %128 = getelementptr inbounds %"struct.std::__1::__compressed_pair_elem", %"struct.std::__1::__compressed_pair_elem"* %127, i32 0, i32 0
  %129 = bitcast %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep"* %128 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %129, i8 0, i64 24, i1 false) #6
  %130 = bitcast %"class.std::__1::__compressed_pair"* %125 to %"struct.std::__1::__compressed_pair_elem.1"*
  store %"struct.std::__1::__compressed_pair_elem.1"* %130, %"struct.std::__1::__compressed_pair_elem.1"** %25, align 8
  %131 = load %"struct.std::__1::__compressed_pair_elem.1"*, %"struct.std::__1::__compressed_pair_elem.1"** %25, align 8
  %132 = bitcast %"struct.std::__1::__compressed_pair_elem.1"* %131 to %"class.std::__1::allocator"*
  store %"class.std::__1::allocator"* %132, %"class.std::__1::allocator"** %24, align 8
  %133 = load %"class.std::__1::allocator"*, %"class.std::__1::allocator"** %24, align 8
  %134 = load i64, i64* %30, align 8
  %135 = load i8, i8* %31, align 1
  call void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc(%"class.std::__1::basic_string"* %121, i64 %134, i8 signext %135)
  %136 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %46, i32 0, i32 0
  %137 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %136, align 8
  store %"class.std::__1::basic_string"* %55, %"class.std::__1::basic_string"** %23, align 8
  %138 = load %"class.std::__1::basic_string"*, %"class.std::__1::basic_string"** %23, align 8
  store %"class.std::__1::basic_string"* %138, %"class.std::__1::basic_string"** %22, align 8
  %139 = load %"class.std::__1::basic_string"*, %"class.std::__1::basic_string"** %22, align 8
  store %"class.std::__1::basic_string"* %139, %"class.std::__1::basic_string"** %21, align 8
  %140 = load %"class.std::__1::basic_string"*, %"class.std::__1::basic_string"** %21, align 8
  %141 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %140, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %141, %"class.std::__1::__compressed_pair"** %20, align 8
  %142 = load %"class.std::__1::__compressed_pair"*, %"class.std::__1::__compressed_pair"** %20, align 8
  %143 = bitcast %"class.std::__1::__compressed_pair"* %142 to %"struct.std::__1::__compressed_pair_elem"*
  store %"struct.std::__1::__compressed_pair_elem"* %143, %"struct.std::__1::__compressed_pair_elem"** %19, align 8
  %144 = load %"struct.std::__1::__compressed_pair_elem"*, %"struct.std::__1::__compressed_pair_elem"** %19, align 8
  %145 = getelementptr inbounds %"struct.std::__1::__compressed_pair_elem", %"struct.std::__1::__compressed_pair_elem"* %144, i32 0, i32 0
  %146 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep", %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep"* %145, i32 0, i32 0
  %147 = bitcast %union.anon* %146 to %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short"*
  %148 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short", %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short"* %147, i32 0, i32 0
  %149 = bitcast %union.anon.0* %148 to i8*
  %150 = load i8, i8* %149, align 8
  %151 = zext i8 %150 to i64
  %152 = and i64 %151, 1
  %153 = icmp ne i64 %152, 0
  br i1 %153, label %154, label %165

; <label>:154:                                    ; preds = %115
  store %"class.std::__1::basic_string"* %139, %"class.std::__1::basic_string"** %13, align 8
  %155 = load %"class.std::__1::basic_string"*, %"class.std::__1::basic_string"** %13, align 8
  %156 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %155, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %156, %"class.std::__1::__compressed_pair"** %12, align 8
  %157 = load %"class.std::__1::__compressed_pair"*, %"class.std::__1::__compressed_pair"** %12, align 8
  %158 = bitcast %"class.std::__1::__compressed_pair"* %157 to %"struct.std::__1::__compressed_pair_elem"*
  store %"struct.std::__1::__compressed_pair_elem"* %158, %"struct.std::__1::__compressed_pair_elem"** %11, align 8
  %159 = load %"struct.std::__1::__compressed_pair_elem"*, %"struct.std::__1::__compressed_pair_elem"** %11, align 8
  %160 = getelementptr inbounds %"struct.std::__1::__compressed_pair_elem", %"struct.std::__1::__compressed_pair_elem"* %159, i32 0, i32 0
  %161 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep", %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep"* %160, i32 0, i32 0
  %162 = bitcast %union.anon* %161 to %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long"*
  %163 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long", %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__long"* %162, i32 0, i32 2
  %164 = load i8*, i8** %163, align 8
  br label %178

; <label>:165:                                    ; preds = %115
  store %"class.std::__1::basic_string"* %139, %"class.std::__1::basic_string"** %18, align 8
  %166 = load %"class.std::__1::basic_string"*, %"class.std::__1::basic_string"** %18, align 8
  %167 = getelementptr inbounds %"class.std::__1::basic_string", %"class.std::__1::basic_string"* %166, i32 0, i32 0
  store %"class.std::__1::__compressed_pair"* %167, %"class.std::__1::__compressed_pair"** %17, align 8
  %168 = load %"class.std::__1::__compressed_pair"*, %"class.std::__1::__compressed_pair"** %17, align 8
  %169 = bitcast %"class.std::__1::__compressed_pair"* %168 to %"struct.std::__1::__compressed_pair_elem"*
  store %"struct.std::__1::__compressed_pair_elem"* %169, %"struct.std::__1::__compressed_pair_elem"** %16, align 8
  %170 = load %"struct.std::__1::__compressed_pair_elem"*, %"struct.std::__1::__compressed_pair_elem"** %16, align 8
  %171 = getelementptr inbounds %"struct.std::__1::__compressed_pair_elem", %"struct.std::__1::__compressed_pair_elem"* %170, i32 0, i32 0
  %172 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep", %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__rep"* %171, i32 0, i32 0
  %173 = bitcast %union.anon* %172 to %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short"*
  %174 = getelementptr inbounds %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short", %"struct.std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__short"* %173, i32 0, i32 1
  %175 = getelementptr inbounds [23 x i8], [23 x i8]* %174, i64 0, i64 0
  store i8* %175, i8** %15, align 8
  %176 = load i8*, i8** %15, align 8
  store i8* %176, i8** %14, align 8
  %177 = load i8*, i8** %14, align 8
  br label %178

; <label>:178:                                    ; preds = %154, %165
  %179 = phi i8* [ %164, %154 ], [ %177, %165 ]
  store i8* %179, i8** %10, align 8
  %180 = load i8*, i8** %10, align 8
  %181 = load i64, i64* %53, align 8
  store %"class.std::__1::basic_streambuf"* %137, %"class.std::__1::basic_streambuf"** %7, align 8
  store i8* %180, i8** %8, align 8
  store i64 %181, i64* %9, align 8
  %182 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %7, align 8
  %183 = load i8*, i8** %8, align 8
  %184 = load i64, i64* %9, align 8
  %185 = bitcast %"class.std::__1::basic_streambuf"* %182 to i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)***
  %186 = load i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)**, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*** %185, align 8
  %187 = getelementptr inbounds i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)** %186, i64 12
  %188 = load i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)** %187, align 8
  %189 = invoke i64 %188(%"class.std::__1::basic_streambuf"* %182, i8* %183, i64 %184)
          to label %190 unwind label %198

; <label>:190:                                    ; preds = %178
  br label %191

; <label>:191:                                    ; preds = %190
  %192 = load i64, i64* %53, align 8
  %193 = icmp ne i64 %189, %192
  br i1 %193, label %194, label %202

; <label>:194:                                    ; preds = %191
  %195 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %46, i32 0, i32 0
  store %"class.std::__1::basic_streambuf"* null, %"class.std::__1::basic_streambuf"** %195, align 8
  %196 = bitcast %"class.std::__1::ostreambuf_iterator"* %45 to i8*
  %197 = bitcast %"class.std::__1::ostreambuf_iterator"* %46 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %196, i8* align 8 %197, i64 8, i1 false)
  store i32 1, i32* %58, align 4
  br label %203

; <label>:198:                                    ; preds = %178
  %199 = landingpad { i8*, i32 }
          cleanup
  %200 = extractvalue { i8*, i32 } %199, 0
  store i8* %200, i8** %56, align 8
  %201 = extractvalue { i8*, i32 } %199, 1
  store i32 %201, i32* %57, align 4
  call void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev(%"class.std::__1::basic_string"* %55) #6
  br label %247

; <label>:202:                                    ; preds = %191
  store i32 0, i32* %58, align 4
  br label %203

; <label>:203:                                    ; preds = %202, %194
  call void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev(%"class.std::__1::basic_string"* %55) #6
  %204 = load i32, i32* %58, align 4
  switch i32 %204, label %252 [
    i32 0, label %205
    i32 1, label %244
  ]

; <label>:205:                                    ; preds = %203
  br label %206

; <label>:206:                                    ; preds = %205, %112
  %207 = load i8*, i8** %49, align 8
  %208 = load i8*, i8** %48, align 8
  %209 = ptrtoint i8* %207 to i64
  %210 = ptrtoint i8* %208 to i64
  %211 = sub i64 %209, %210
  store i64 %211, i64* %54, align 8
  %212 = load i64, i64* %54, align 8
  %213 = icmp sgt i64 %212, 0
  br i1 %213, label %214, label %234

; <label>:214:                                    ; preds = %206
  %215 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %46, i32 0, i32 0
  %216 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %215, align 8
  %217 = load i8*, i8** %48, align 8
  %218 = load i64, i64* %54, align 8
  store %"class.std::__1::basic_streambuf"* %216, %"class.std::__1::basic_streambuf"** %38, align 8
  store i8* %217, i8** %39, align 8
  store i64 %218, i64* %40, align 8
  %219 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %38, align 8
  %220 = load i8*, i8** %39, align 8
  %221 = load i64, i64* %40, align 8
  %222 = bitcast %"class.std::__1::basic_streambuf"* %219 to i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)***
  %223 = load i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)**, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*** %222, align 8
  %224 = getelementptr inbounds i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)** %223, i64 12
  %225 = load i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)*, i64 (%"class.std::__1::basic_streambuf"*, i8*, i64)** %224, align 8
  %226 = call i64 %225(%"class.std::__1::basic_streambuf"* %219, i8* %220, i64 %221)
  %227 = load i64, i64* %54, align 8
  %228 = icmp ne i64 %226, %227
  br i1 %228, label %229, label %233

; <label>:229:                                    ; preds = %214
  %230 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %46, i32 0, i32 0
  store %"class.std::__1::basic_streambuf"* null, %"class.std::__1::basic_streambuf"** %230, align 8
  %231 = bitcast %"class.std::__1::ostreambuf_iterator"* %45 to i8*
  %232 = bitcast %"class.std::__1::ostreambuf_iterator"* %46 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %231, i8* align 8 %232, i64 8, i1 false)
  br label %244

; <label>:233:                                    ; preds = %214
  br label %234

; <label>:234:                                    ; preds = %233, %206
  %235 = load %"class.std::__1::ios_base"*, %"class.std::__1::ios_base"** %50, align 8
  store %"class.std::__1::ios_base"* %235, %"class.std::__1::ios_base"** %41, align 8
  store i64 0, i64* %42, align 8
  %236 = load %"class.std::__1::ios_base"*, %"class.std::__1::ios_base"** %41, align 8
  %237 = getelementptr inbounds %"class.std::__1::ios_base", %"class.std::__1::ios_base"* %236, i32 0, i32 3
  %238 = load i64, i64* %237, align 8
  store i64 %238, i64* %43, align 8
  %239 = load i64, i64* %42, align 8
  %240 = getelementptr inbounds %"class.std::__1::ios_base", %"class.std::__1::ios_base"* %236, i32 0, i32 3
  store i64 %239, i64* %240, align 8
  %241 = load i64, i64* %43, align 8
  %242 = bitcast %"class.std::__1::ostreambuf_iterator"* %45 to i8*
  %243 = bitcast %"class.std::__1::ostreambuf_iterator"* %46 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %242, i8* align 8 %243, i64 8, i1 false)
  br label %244

; <label>:244:                                    ; preds = %234, %229, %203, %107, %63
  %245 = getelementptr inbounds %"class.std::__1::ostreambuf_iterator", %"class.std::__1::ostreambuf_iterator"* %45, i32 0, i32 0
  %246 = load %"class.std::__1::basic_streambuf"*, %"class.std::__1::basic_streambuf"** %245, align 8
  ret %"class.std::__1::basic_streambuf"* %246

; <label>:247:                                    ; preds = %198
  %248 = load i8*, i8** %56, align 8
  %249 = load i32, i32* %57, align 4
  %250 = insertvalue { i8*, i32 } undef, i8* %248, 0
  %251 = insertvalue { i8*, i32 } %250, i32 %249, 1
  resume { i8*, i32 } %251

; <label>:252:                                    ; preds = %203
  unreachable
}

; Function Attrs: nounwind
declare void @_ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev(%"class.std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry"*) unnamed_addr #3

declare i8* @__cxa_begin_catch(i8*)

declare void @_ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__1::ios_base"*) #2

declare void @__cxa_end_catch()

; Function Attrs: noinline noreturn nounwind
define linkonce_odr hidden void @__clang_call_terminate(i8*) #4 {
  %2 = call i8* @__cxa_begin_catch(i8* %0) #6
  call void @_ZSt9terminatev() #7
  unreachable
}

declare void @_ZSt9terminatev()

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #5

; Function Attrs: nounwind
declare void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev(%"class.std::__1::basic_string"*) unnamed_addr #3

declare void @_ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc(%"class.std::__1::basic_string"*, i64, i8 signext) #2

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1) #5

; Function Attrs: noinline nounwind optnone ssp uwtable
define linkonce_odr zeroext i1 @_ZNSt3__111char_traitsIcE11eq_int_typeEii(i32, i32) #1 align 2 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  %5 = load i32, i32* %3, align 4
  %6 = load i32, i32* %4, align 4
  %7 = icmp eq i32 %5, %6
  ret i1 %7
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define linkonce_odr i32 @_ZNSt3__111char_traitsIcE3eofEv() #1 align 2 {
  ret i32 -1
}

declare void @_ZNKSt3__18ios_base6getlocEv(%"class.std::__1::locale"* sret, %"class.std::__1::ios_base"*) #2

; Function Attrs: nounwind
declare void @_ZNSt3__16localeD1Ev(%"class.std::__1::locale"*) unnamed_addr #3

declare %"class.std::__1::locale::facet"* @_ZNKSt3__16locale9use_facetERNS0_2idE(%"class.std::__1::locale"*, %"class.std::__1::locale::id"* dereferenceable(16)) #2

declare void @_ZNSt3__18ios_base5clearEj(%"class.std::__1::ios_base"*, i32) #2

; Function Attrs: nounwind
declare i64 @strlen(i8*) #3

attributes #0 = { noinline optnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noinline nounwind optnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noinline noreturn nounwind }
attributes #5 = { argmemonly nounwind }
attributes #6 = { nounwind }
attributes #7 = { noreturn nounwind }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{!"clang version 7.0.1 (tags/RELEASE_701/final)"}
