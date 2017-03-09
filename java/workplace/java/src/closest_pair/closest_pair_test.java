package closest_pair;

import java.util.ArrayList;  
import java.util.Arrays;  
import java.util.Comparator;  
  
  
public class closest_pair_test {  
      
    public static void main(String[] args) {  
        initializepoint();  
        point[]result = closest_pair(P);  
        dist = distance(result);  
        System.out.println("距离最近的两点为：");  
        print(result);  
        System.out.println("距离为："+dist);  
    }  
    private static double dist;  
    private static point[] P;  
    private static Comparator<point> ycompar = new Comparator<point>() {  //根据y坐标比较的比较器  
        @Override  
        public int compare(point o1, point o2) {  
            if(o1.y<o2.y){  
                return -1;  
            }  
            else if(o1.y>o2.y){  
                return 1;  
            }  
            return 0;  
        }  
    };  
    private static Comparator<point> xcompar = new Comparator<point>() {    //根据x坐标比较的比较器  
        @Override  
        public int compare(point o1, point o2) {  
            if(o1.x<o2.x){  
                return -1;  
            }  
            else if(o1.x>o2.x){  
                return 1;  
            }  
            return 0;  
        }  
    };  
      
  
    //初始化点数组  
    /*
	1 1
	2 2
	4 4
	8 8
	2 3
	5 6
	7 9
	11 11*/
    private static void initializepoint() {  
        P = new point[8];  
        for(int i=0;i<P.length;i++){  
            P[i] = new point();  
        }  
        P[0].x = 1;  
        P[0].y = 1;  
        P[1].x = 2;  
        P[1].y = 2;  
        P[2].x = 4;  
        P[2].y = 4;  
        P[3].x = 8;  
        P[3].y = 8;  
        P[4].x = 2;  
        P[4].y = 3; 
        P[5].x = 5;
        P[5].y = 6;
        P[6].x = 7;
        P[6].y = 9;
        P[7].x = 11;
        P[7].y = 11;
    }  
  
    //主函数  
    public static point[] closest_pair(point[] points) {  
        point[] px = points.clone();  
        Arrays.sort(px,xcompar);  
        point[] py = points.clone();  
        Arrays.sort(py,ycompar);  
        point[] result = closest_pair_rec(px,py);  
        return result;  
          
    }  
      
    public static point[] closest_pair_rec(point[]px,point[]py){  
          
        point minFirstpoint = null;  
        point minSecondpoint = null;  
        double mindistance = 0;  
          
        if(px.length<=3){        //出口  
            double mindist = Double.MAX_VALUE;  
            int mini = 0;  
            int minj = 0;  
            for(int i=0;i<px.length;i++){  
                for(int j=i+1;j<px.length;j++){  
                    if(mindist>distance(new point[]{px[i],px[j]})){  
                        mindist = distance(new point[]{px[i],px[j]});  
                        mini = i;  
                        minj = j;  
                    }  
                }  
            }  
            return new point[]{px[mini],px[minj]};  
        }  
        point[] Q = Arrays.copyOfRange(px, 0, px.length/2+1);  
        point[] R = Arrays.copyOfRange(px, px.length/2+1, px.length);  
          
        point[] Qx = Q.clone();  
        Arrays.sort(Qx, xcompar);  
        point[] Qy = Q.clone();  
        Arrays.sort(Qy, ycompar);  
          
        point[] Rx = R.clone();  
        Arrays.sort(Rx, xcompar);  
        point[]Ry = R.clone();  
        Arrays.sort(Ry, ycompar);  
          
        point[] q = closest_pair_rec(Qx,Qy);  
        point[] r = closest_pair_rec(Rx,Ry);  
          
        double qd = distance(q);  
        double rd = distance(r);  
        double delta = Math.min(qd,rd);  
        if(delta==qd){  
            minFirstpoint = q[0];  
            minSecondpoint = q[1];  
        }  
        else{  
            minFirstpoint = r[0];  
            minSecondpoint = r[1];  
        }  
        mindistance = delta;  
          
        int maxx = Qx[Qx.length-1].x;   //分割线  
          
        //找到与分割线距离小于delta的部分点放到S中  
        ArrayList<point> Stmp = new ArrayList<point>();  
        for(int i=0;i<px.length;i++){  
            if(Math.abs(px[i].x-maxx)<delta){  
                Stmp.add(px[i]);  
            }  
        }  
        point[]S = Stmp.toArray(new point[0]);  
        point[] Sy = S.clone();  
        Arrays.sort(Sy,ycompar);  
          
        //寻找15个点之内的点，并比较距离,找出最小距离的得点 ，每个点至多比较8个点，因此复杂度为O(8n)  
        double secondMinDistance = Double.MAX_VALUE;  
        point tmpminFirst = null;  
        point tmpminSecond = null;  
        for(int i=0;i<Sy.length;i++){  
            point basep = Sy[i];  
            for(int j=i+1;j<Sy.length;j++){  
                point compp = Sy[j];  
                if((compp.y-basep.y < 2*delta)&&Math.abs(compp.x-basep.x)<2*delta){   //如果在15个点之内，即x和y坐标相差都在2*delta之内   
                    double tmpdis = distance(new point[]{basep,compp});  
                    if(secondMinDistance>tmpdis){  
                        secondMinDistance = tmpdis;  
                        tmpminSecond = compp;  
                        tmpminFirst = basep;  
                    }  
                }  
                else{  
                    break;  
                }  
            }  
        }  
        if(secondMinDistance<mindistance){  
            return new point[]{tmpminFirst,tmpminSecond};  
        }  
        else{  
            return new point[]{minFirstpoint,minSecondpoint};  
        }  
    }  
      
    private static double distance(point[] q) {  
        return Math.pow(Math.pow(q[0].x-q[1].x,2)+Math.pow(q[0].y-q[1].y,2), 0.5);  
    }  
  
    private static void print(point[]ps){  
        for(point p:ps){  
            System.out.println("x="+p.x+",y="+p.y);  
        }  
    }  
}  