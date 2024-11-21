set(Boost_USE_STATIC_LIBS OFF)
enable_testing()

# Поиск необходимых компонентов Boost
find_package(Boost REQUIRED COMPONENTS thread filesystem system program_options date_time unit_test_framework)

# Добавляем тесты
add_executable(server_tests
    test_server.cpp
    ${CMAKE_SOURCE_DIR}/src/server.cpp
    ${CMAKE_SOURCE_DIR}/src_client/client.cpp
    main.cpp
)

# Линкуем с Boost
target_link_libraries(server_tests
    Boost::thread
    Boost::filesystem
    Boost::system
    Boost::program_options
    Boost::date_time
    Boost::unit_test_framework
)

# Указываем директории для заголовочных файлов
target_include_directories(server_tests PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src_client
)

# Указываем, что проект — консольное приложение
if(WIN32)
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -subsystem:console")
    target_link_libraries(server_tests wsock32 ws2_32)
endif()

# Регистрируем тесты
add_test(Server_t server_tests)

# Указываем пути для установки
install(TARGETS server_tests
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
