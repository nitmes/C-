cmake_minimum_required(VERSION 3.20)


add_executable(SpiderApp
	main.cpp
	http_utils.h
	http_utils.cpp
	link.h
	)

target_compile_features(SpiderApp PRIVATE cxx_std_17) 

target_link_libraries(SpiderApp pqxx)

target_include_directories(SpiderApp PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(SpiderApp ${Boost_LIBRARIES})

target_link_libraries(SpiderApp OpenSSL::SSL)

target_include_directories(ini_parser PUBLIC "../ini_parser")

target_link_libraries(SpiderApp ini_parser)

target_include_directories(data_base PUBLIC "../data_base")

target_link_libraries(SpiderApp data_base)
