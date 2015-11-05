#include <boost/config.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp>

enum family { Jeanie, Debbie, Rick, John, Amanda, Margaret, Benjamin, N };

int main(int argc, char *argv[]) {

    using namespace boost;
    using namespace std;

    cout << "Initializing Jarvis..." << endl;

    const char *name[] = { "Jeanie", "Debbie", "Rick", "John", "Amanda","Margaret", "Benjamin"};

    adjacency_list <> graph(family::N);
    add_edge(family::Jeanie, family::Debbie, graph);
    add_edge(family::Jeanie, family::Rick, graph);
    add_edge(family::Jeanie, family::John, graph);
    add_edge(family::Debbie, family::Amanda, graph);
    add_edge(family::Rick, family::Margaret, graph);
    add_edge(family::John, family::Benjamin, graph);

    graph_traits < adjacency_list <> >::vertex_iterator i, end;
    graph_traits < adjacency_list <> >::adjacency_iterator ai, a_end;
    property_map < adjacency_list <>, vertex_index_t >::type index_map = get(vertex_index, graph);

    for (boost::tie(i, end) = vertices(graph); i != end; ++i) {
        std::cout << name[get(index_map, *i)];
        boost::tie(ai, a_end) = adjacent_vertices(*i, graph);
        if (ai == a_end)
            std::cout << " has no children";
        else
            std::cout << " is the parent of ";
        for (; ai != a_end; ++ai) {
            std::cout << name[get(index_map, *ai)];
            if (boost::next(ai) != a_end)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }


        return EXIT_SUCCESS;
}
