/* Authors: Zhongyue Zhang <zhangz6@cs.washington.edu>

License: BSD 3 clause
================================================= */
#ifndef CYFLANN_INDEX_H_
#define CYFLANN_INDEX_H_

#include <flann/flann.hpp> 
#include <vector>
using namespace flann;

class CyflannIndex {
public:
    
    CyflannIndex(const std::vector<float>& dataset, int num_dims);

    CyflannIndex(const std::vector<float>& dataset, int num_dims,
            float target_precision);

    CyflannIndex(const std::vector<float>& dataset, int num_dims,
            float target_precision, std::string filename);

    ~CyflannIndex();
    
    void buildIndex();

    void knnSearch(const std::vector<float>& queries,
            std::vector< std::vector<int> >& indices,
            std::vector< std::vector<float> >& dists,
            int knn, int num_dims);

    int radiusSearch(const std::vector<float>& queries,
            std::vector< std::vector<int> >& indices,
            std::vector< std::vector<float> >& dists,
            float radius, int num_dims);

    void save(std::string filename);

    int veclen();

    int size();

private:
    float* dataset_;
    Index< L2<float> >* index_;
};

// Takes a flattened matrix queries, with dimension num_dims.
// For each data point in queries, search for neighbors within the radius.
int radiusSearch(const std::vector<float>& queries,
		 std::vector< std::vector<int> >& indices,
                 std::vector< std::vector<float> >& dists,
		 float radius, int num_dims);

#endif // CYFLANN_INDEX_H_
