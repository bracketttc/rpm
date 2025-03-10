add_library(librpmbuild SHARED)
set_target_properties(librpmbuild PROPERTIES
	VERSION ${RPM_LIBVERSION}
	SOVERSION ${RPM_SOVERSION}
)
target_sources(librpmbuild PRIVATE
	build.c files.c misc.c pack.c
	parseSimpleScript.c parseChangelog.c parseDescription.c
	parseFiles.c parsePreamble.c parsePrep.c parseReqs.c parseScript.c
	parseSpec.c parseList.c reqprov.c rpmfc.c spec.c
	parsePolicies.c policies.c
	rpmbuild_internal.h rpmbuild_misc.h
	speclua.c
)

target_include_directories(librpmbuild PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/rpmio
	${CMAKE_SOURCE_DIR}/lib
)

target_link_libraries(librpmbuild PUBLIC librpmio librpm)
target_link_libraries(librpmbuild PRIVATE
	libmisc
	PkgConfig::POPT
	PkgConfig::LIBELF
	PkgConfig::LIBDW
	LUA::LUA
	MAGIC::MAGIC
)

if(WITH_CAP)
	target_link_libraries(librpmbuild PRIVATE PkgConfig::LIBCAP)
endif()

if(OpenMP_C_FOUND)
	target_link_libraries(librpmbuild PRIVATE OpenMP::OpenMP_C)
endif()


install(TARGETS librpmbuild EXPORT rpm-targets)
