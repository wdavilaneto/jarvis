#define BOOST_TEST_MODULE FannTestTestSuite

#include <boost/test/unit_test.hpp>
#include <boost/make_shared.hpp>

#include <fann.h>
#include <fann_cpp.h>

#include <iostream>

using namespace FANN;
using boost::shared_ptr;
using boost::make_shared;

BOOST_AUTO_TEST_CASE(FannTest) {

    const unsigned int num_layers = 3;
    const unsigned int num_input = 2;
    const unsigned int num_hidden = 3;
    const unsigned int num_output = 1;

    const float desired_error = (const float) 0.001;
    const unsigned int max_epochs = 500000;
    const unsigned int epochs_between_reports = 1000;

    BOOST_TEST_MESSAGE("Training NN");

    neural_net net;

    net.create_standard(num_layers, num_input, num_hidden, num_output);
    net.set_activation_function_hidden(activation_function_enum::SIGMOID_SYMMETRIC);
    net.set_activation_function_output(activation_function_enum::SIGMOID_SYMMETRIC);
    net.train_on_file("xor_float.data", max_epochs, epochs_between_reports, desired_error);
    net.save("xor_float.net");

    BOOST_TEST_MESSAGE("Testing NN");

    neural_net ann;
    ann.create_from_file("xor_float.net");

    fann_type input[2];
    input[0] = -1;
    input[1] = 1;

    fann_type* output = ann.run(input);

    std::cout << "xor test (" << input[0] <<" , " << input[1] << ") => " << output[0];

    BOOST_CHECK( output[0] > 0.8 );

}
