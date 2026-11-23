set(CMAKE_CXX_COMPILER "/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/intel-oneapi-compilers-2023.1.0-6g2jkivucihw2lzbloyvig7gnmldj6vk/compiler/2023.1.0/linux/bin/icpx")
set(CMAKE_CXX_COMPILER_ARG1 "")
set(CMAKE_CXX_COMPILER_ID "IntelLLVM")
set(CMAKE_CXX_COMPILER_VERSION "2023.1.0")
set(CMAKE_CXX_COMPILER_VERSION_INTERNAL "")
set(CMAKE_CXX_COMPILER_WRAPPER "")
set(CMAKE_CXX_STANDARD_COMPUTED_DEFAULT "17")
set(CMAKE_CXX_EXTENSIONS_COMPUTED_DEFAULT "ON")
set(CMAKE_CXX_COMPILE_FEATURES "cxx_std_98;cxx_template_template_parameters;cxx_std_11;cxx_alias_templates;cxx_alignas;cxx_alignof;cxx_attributes;cxx_auto_type;cxx_constexpr;cxx_decltype;cxx_decltype_incomplete_return_types;cxx_default_function_template_args;cxx_defaulted_functions;cxx_defaulted_move_initializers;cxx_delegating_constructors;cxx_deleted_functions;cxx_enum_forward_declarations;cxx_explicit_conversions;cxx_extended_friend_declarations;cxx_extern_templates;cxx_final;cxx_func_identifier;cxx_generalized_initializers;cxx_inheriting_constructors;cxx_inline_namespaces;cxx_lambdas;cxx_local_type_template_args;cxx_long_long_type;cxx_noexcept;cxx_nonstatic_member_init;cxx_nullptr;cxx_override;cxx_range_for;cxx_raw_string_literals;cxx_reference_qualified_functions;cxx_right_angle_brackets;cxx_rvalue_references;cxx_sizeof_member;cxx_static_assert;cxx_strong_enums;cxx_thread_local;cxx_trailing_return_types;cxx_unicode_literals;cxx_uniform_initialization;cxx_unrestricted_unions;cxx_user_literals;cxx_variadic_macros;cxx_variadic_templates;cxx_std_14;cxx_aggregate_default_initializers;cxx_attribute_deprecated;cxx_binary_literals;cxx_contextual_conversions;cxx_decltype_auto;cxx_digit_separators;cxx_generic_lambdas;cxx_lambda_init_captures;cxx_relaxed_constexpr;cxx_return_type_deduction;cxx_variable_templates;cxx_std_17;cxx_std_20;cxx_std_23")
set(CMAKE_CXX98_COMPILE_FEATURES "cxx_std_98;cxx_template_template_parameters")
set(CMAKE_CXX11_COMPILE_FEATURES "cxx_std_11;cxx_alias_templates;cxx_alignas;cxx_alignof;cxx_attributes;cxx_auto_type;cxx_constexpr;cxx_decltype;cxx_decltype_incomplete_return_types;cxx_default_function_template_args;cxx_defaulted_functions;cxx_defaulted_move_initializers;cxx_delegating_constructors;cxx_deleted_functions;cxx_enum_forward_declarations;cxx_explicit_conversions;cxx_extended_friend_declarations;cxx_extern_templates;cxx_final;cxx_func_identifier;cxx_generalized_initializers;cxx_inheriting_constructors;cxx_inline_namespaces;cxx_lambdas;cxx_local_type_template_args;cxx_long_long_type;cxx_noexcept;cxx_nonstatic_member_init;cxx_nullptr;cxx_override;cxx_range_for;cxx_raw_string_literals;cxx_reference_qualified_functions;cxx_right_angle_brackets;cxx_rvalue_references;cxx_sizeof_member;cxx_static_assert;cxx_strong_enums;cxx_thread_local;cxx_trailing_return_types;cxx_unicode_literals;cxx_uniform_initialization;cxx_unrestricted_unions;cxx_user_literals;cxx_variadic_macros;cxx_variadic_templates")
set(CMAKE_CXX14_COMPILE_FEATURES "cxx_std_14;cxx_aggregate_default_initializers;cxx_attribute_deprecated;cxx_binary_literals;cxx_contextual_conversions;cxx_decltype_auto;cxx_digit_separators;cxx_generic_lambdas;cxx_lambda_init_captures;cxx_relaxed_constexpr;cxx_return_type_deduction;cxx_variable_templates")
set(CMAKE_CXX17_COMPILE_FEATURES "cxx_std_17")
set(CMAKE_CXX20_COMPILE_FEATURES "cxx_std_20")
set(CMAKE_CXX23_COMPILE_FEATURES "cxx_std_23")

set(CMAKE_CXX_PLATFORM_ID "Linux")
set(CMAKE_CXX_SIMULATE_ID "GNU")
set(CMAKE_CXX_COMPILER_FRONTEND_VARIANT "GNU")
set(CMAKE_CXX_SIMULATE_VERSION "4.2.1")




set(CMAKE_AR "/usr/bin/ar")
set(CMAKE_CXX_COMPILER_AR "/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/intel-oneapi-compilers-2023.1.0-6g2jkivucihw2lzbloyvig7gnmldj6vk/compiler/2023.1.0/linux/bin-llvm/llvm-ar")
set(CMAKE_RANLIB "/usr/bin/ranlib")
set(CMAKE_CXX_COMPILER_RANLIB "/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/intel-oneapi-compilers-2023.1.0-6g2jkivucihw2lzbloyvig7gnmldj6vk/compiler/2023.1.0/linux/bin-llvm/llvm-ranlib")
set(CMAKE_LINKER "/usr/bin/ld")
set(CMAKE_MT "")
set(CMAKE_COMPILER_IS_GNUCXX )
set(CMAKE_CXX_COMPILER_LOADED 1)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_CXX_ABI_COMPILED TRUE)

set(CMAKE_CXX_COMPILER_ENV_VAR "CXX")

set(CMAKE_CXX_COMPILER_ID_RUN 1)
set(CMAKE_CXX_SOURCE_FILE_EXTENSIONS C;M;c++;cc;cpp;cxx;m;mm;mpp;CPP;ixx;cppm)
set(CMAKE_CXX_IGNORE_EXTENSIONS inl;h;hpp;HPP;H;o;O;obj;OBJ;def;DEF;rc;RC)

foreach (lang C OBJC OBJCXX)
  if (CMAKE_${lang}_COMPILER_ID_RUN)
    foreach(extension IN LISTS CMAKE_${lang}_SOURCE_FILE_EXTENSIONS)
      list(REMOVE_ITEM CMAKE_CXX_SOURCE_FILE_EXTENSIONS ${extension})
    endforeach()
  endif()
endforeach()

set(CMAKE_CXX_LINKER_PREFERENCE 30)
set(CMAKE_CXX_LINKER_PREFERENCE_PROPAGATES 1)

# Save compiler ABI information.
set(CMAKE_CXX_SIZEOF_DATA_PTR "8")
set(CMAKE_CXX_COMPILER_ABI "ELF")
set(CMAKE_CXX_BYTE_ORDER "LITTLE_ENDIAN")
set(CMAKE_CXX_LIBRARY_ARCHITECTURE "")

if(CMAKE_CXX_SIZEOF_DATA_PTR)
  set(CMAKE_SIZEOF_VOID_P "${CMAKE_CXX_SIZEOF_DATA_PTR}")
endif()

if(CMAKE_CXX_COMPILER_ABI)
  set(CMAKE_INTERNAL_PLATFORM_ABI "${CMAKE_CXX_COMPILER_ABI}")
endif()

if(CMAKE_CXX_LIBRARY_ARCHITECTURE)
  set(CMAKE_LIBRARY_ARCHITECTURE "")
endif()

set(CMAKE_CXX_CL_SHOWINCLUDES_PREFIX "")
if(CMAKE_CXX_CL_SHOWINCLUDES_PREFIX)
  set(CMAKE_CL_SHOWINCLUDES_PREFIX "${CMAKE_CXX_CL_SHOWINCLUDES_PREFIX}")
endif()





set(CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES "/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/libx11-1.8.4-aj3pqduvv2fzv7fo2yjbbrdshtniiary/include;/mnt/lustre/localsoft/hdf5-V1.14.3-oneapi/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/zlib-1.2.13-iogzjoqvug4n4pylhaf3xsdpvs2wwcud/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/pkgconf-1.9.5-vwu5nv4iz5oh4aqxsvgjnusn7ag5toxr/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/libaec-1.0.6-bxqbachc63ugwtruaejyxkei2zwiamqm/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/intel-oneapi-mpi-2021.9.0-alz6lstmpi2dfpkk3trayc2xqpj54hi6/mpi/2021.9.0/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/intel-oneapi-mpi-2021.9.0-alz6lstmpi2dfpkk3trayc2xqpj54hi6/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/libxmu-1.1.4-wss4pouo3czvkz4gwobnm5tbiexmn7av/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/libx11-1.8.4-lm4p7le7g7u2btptzza7v6qysvfiewl5/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/python-3.10.10-ze5tho3bqaggy3kl6uku3a3353sb37j6/include;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/intel-oneapi-compilers-2023.1.0-6g2jkivucihw2lzbloyvig7gnmldj6vk/compiler/2023.1.0/linux/compiler/include;/usr/include/c++/8;/usr/include/c++/8/x86_64-redhat-linux;/usr/include/c++/8/backward;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/intel-oneapi-compilers-2023.1.0-6g2jkivucihw2lzbloyvig7gnmldj6vk/compiler/2023.1.0/linux/lib/clang/16/include;/usr/local/include;/usr/include")
set(CMAKE_CXX_IMPLICIT_LINK_LIBRARIES "svml;irng;stdc++;imf;m;gcc_s;gcc;irc;dl;gcc_s;gcc;c;gcc_s;gcc;irc_s")
set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES "/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/intel-oneapi-compilers-2023.1.0-6g2jkivucihw2lzbloyvig7gnmldj6vk/compiler/2023.1.0/linux/compiler/lib/intel64_lin;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/intel-oneapi-compilers-2023.1.0-6g2jkivucihw2lzbloyvig7gnmldj6vk/compiler/2023.1.0/linux/lib;/usr/lib/gcc/x86_64-redhat-linux/8;/usr/lib64;/lib64;/usr/lib;/lib;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/intel-oneapi-mpi-2021.9.0-alz6lstmpi2dfpkk3trayc2xqpj54hi6/mpi/2021.9.0/libfabric/lib;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/intel-oneapi-mpi-2021.9.0-alz6lstmpi2dfpkk3trayc2xqpj54hi6/mpi/2021.9.0/lib/release;/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/intel-oneapi-mpi-2021.9.0-alz6lstmpi2dfpkk3trayc2xqpj54hi6/mpi/2021.9.0/lib")
set(CMAKE_CXX_IMPLICIT_LINK_FRAMEWORK_DIRECTORIES "")
