//
//  main.cpp
//  PCLTest
//
//  Created by moccow on 2018/03/05.
//  Copyright © 2018年 moccow. All rights reserved.
//

// データを読み込むだけのサンプル
// http://derivecv.tumblr.com/post/12067667202

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int　main (int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    
    if (pcl::io::loadPCDFile<pcl::PointXYZ>("/Users/moccow/SRC/C++/PCLTest/milk_cartoon_all_small_clorox.pcd", *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }
    std::cout << "Loaded "
    << cloud->width * cloud->height
    << " data points from raw_0.pcd with the following fields: "
    << std::endl;
    for (size_t i = 0; i < cloud->points.size (); ++i)
        std::cout << "    " << cloud->points[i].x
        << " "    << cloud->points[i].y
        << " "    << cloud->points[i].z << std::endl;
    
    return (0);
}
