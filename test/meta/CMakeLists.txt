ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS unit_test_framework filesystem)

add_executable(MetaTest MetaTest.cpp)

target_link_libraries(
        MetaTest
        ${Boost_LIBRARIES}
        meta-analyzers
        meta-filters
        meta-tokenizers
        meta-classify
        meta-kernel
        meta-corpus
        meta-embeddings
        meta-features
        meta-index
        meta-eval
        meta-io
        meta-learn
        meta-loss
        meta-language-model
        meta-lm-analyzers
        meta-parser
        meta-parser-io
        meta-tree-visitors
        meta-sequence
        meta-crf
        meta-utf
)

