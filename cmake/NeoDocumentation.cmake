if (NEOTEST_STANDALONE AND NEOTEST_BUILD_DOC)
    # doxygen documentation (https://vicrucann.github.io/tutorials/quick-cmake-doxygen/)
    # check if Doxygen is installed
    find_package(Doxygen)
    if (DOXYGEN_FOUND)
        # set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        if (EXISTS ${DOXYGEN_IN})
            # request to configure the file
            configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
            message(STATUS "Doxygen configured")

            # note the option ALL which allows to build the docs together with the application
            add_custom_target(doc_doxygen ALL
                    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM)
            message(STATUS "Added target doc_doxygen_${Target}")

#            if (TARGET doc_doxygen)
#                add_dependencies(doc_doxygen doc_doxygen_${Target})
#            else ()
#                add_custom_target(doc_doxygen DEPENDS doc_doxygen_${Target})
#            endif ()
        else ()
            message(WARNING "doxygen documentation requested, but file ${DOXYGEN_IN} does not exist.")
        endif ()
    else (DOXYGEN_FOUND)
        message(WARNING "Doxygen must be installed and accessible to generate the doxygen documentation.")
    endif (DOXYGEN_FOUND)
endif ()