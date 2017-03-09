#include<iostream>
#include<vector>
#include <climits>
#include <algorithm> 

using namespace std;

struct point {
	int x;
	int y;
};

bool compare_x(const point &p1, const point &p2){
	return p1.x<p2.x;
}

bool compare_y(const point &p1, const point &p2){
	return p1.y<p2.y;
}

int distance(vector<point> points) {
	int distance = (points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y);
		return distance;
} 



vector<point> Closest_Pair_Rec(vector<point> pointx) {
	
	//if|P|<=3，直接计算最小距离的点对
	if (pointx.size() <= 3) {
		int mindistance_three = INT_MAX;
		int points_i = 0;
		int points_j = 0;
		for (int i = 0; i < pointx.size(); i++) {
			for(int j = i + 1;j<pointx.size();j++){
				vector<point> p;
				p.push_back(pointx[i]);
				p.push_back(pointx[j]);
				int x = distance(p);
				if(mindistance_three > x){
					mindistance_three = x;
					points_i = i;
					points_j = j;
				}
			}
		}
		vector<point> p;
		p.push_back(pointx[points_i]);
		p.push_back(pointx[points_j]);
		return p;
	}
	
	//构造Qx，Qy，Rx，Ry
	vector<point> Q,R;
	
	for(int i=0;i<pointx.size();i++){
		if(i>=0&&i<pointx.size()/2){
			Q.push_back(pointx[i]);
		}else{
			R.push_back(pointx[i]);
		}
	}
    
	sort(Q.begin(),Q.end(),compare_x);
	
	sort(R.begin(),R.end(),compare_x);
	
	//进行递归分别得到Q和R最小距离点对
	vector<point> Q_result = Closest_Pair_Rec(Q);
	vector<point> R_result = Closest_Pair_Rec(R);
	
	//Q和R点对之间的小值
	int mindistance = distance(Q_result);
	if(distance(R_result)<mindistance){
		mindistance = distance(R_result);
	}
	point min_i;
	point min_j;
	
	//假如中间区域不存在比QR最小距离更小的值，则返回点集便是QR中距离更小的点集
	if(mindistance == distance(Q_result)){
		min_i = Q_result[0];
		min_j = Q_result[1];
	}
	if(mindistance == distance(R_result)){
		min_i = R_result[0];
		min_j = R_result[1];
	}
	
	//Q中点的最大x坐标
	int Q_max_x = Q[Q.size()-1].x;
	
	//构造与线x=Q_max_x距离小于mindistance的点集S
	vector<point> S;
	for(int i=0;i<pointx.size();i++){
		if(abs(pointx[i].x-Q_max_x)<mindistance){
			S.push_back(pointx[i]);
		}
	}
	
	//对S进行y的排序
	sort(S.begin(),S.end(),compare_y);
	
	//找15个点之内的点，并比较距离,找出最小距离的的点 
	int mindistance_mid = INT_MAX;
	point min_mid_i;
	point min_mid_j;
	for(int i=0;i<S.size();i++){
        point basep = S[i];
        for(int j=i+1;j<S.size();j++){
            point compp = S[j];
            if((compp.y-basep.y < 2*mindistance)&&abs(compp.x-basep.x)<2*mindistance){
            	vector<point> p;
				p.push_back(basep);
				p.push_back(compp);
				int x = distance(p);
                if(mindistance_mid>x){
                	mindistance_mid = x;
                    min_mid_i = compp;
                    min_mid_j = basep;
                }
            }
        }
    }
	
	//判断QR中的最小距离和中间区域的最小距离哪个更小并返回
	if(mindistance_mid<mindistance){
		vector<point> p;
		p.push_back(min_mid_i);
		p.push_back(min_mid_j);
		return p;
	}else{
		vector<point> p;
		p.push_back(min_i);
		p.push_back(min_j);
		return p;
	}
}

int Closest_Pair(vector<point> points) {
	sort(points.begin(),points.end(),compare_x);
	vector<point> result = Closest_Pair_Rec(points);
	return distance(result);
}

int main() {
	int point_num;
	cin>>point_num; 
    vector<point> points;
	for (int i = 0; i < point_num; i++) {
		int x,y;
		cin>>x>>y;
		point p = {x,y};
		points.push_back(p);
	}
	cout<<Closest_Pair(points);
}

