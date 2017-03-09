using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MeetingDAL;
using MeetingModel;

namespace MeetingBLL
{
    public class MeetingsBLL
    {
        //创建MeetingDAL实体对象
        MeetingsDAL meetingdal = new MeetingsDAL();
        //添加会议
        public int AddMeeting(Meeting meeting)
        {
            int issuccess = meetingdal.AddMeeting(meeting);
            return issuccess;
        }
        //删除会议
        public void DeleteMeeting(int MeetingID)
        {
            meetingdal.DeleteMeeting(MeetingID);
        }
        //更新会议
        public int UpdateMeeting(Meeting meeting)
        {
            int issuccess = meetingdal.UpdateMeeting(meeting);
            return issuccess;
        }
        //查看会议
        public List<Meeting> GetAllMeetingList()
        {
            return meetingdal.GetAllMeetingList();
        }
        public Meeting GetMeetingInfo(int MeeetingID)
        {
            return meetingdal.GetMeetingInfo(MeeetingID);
        }
        public int GetMeetingCount()
        {
            return meetingdal.GetMeetingCount();
        }

        //查看与会人员
        public List<attend> GetAttendList(int MeetingID)
        {
            return meetingdal.GetAttendList(MeetingID);
        }
        //添加与会人员
        public int AddAttend(attend attend)
        {
            int issuccess = meetingdal.AddAttend(attend);
            return issuccess;
        }
        //删除与会人员
        public void DeleteAttend(int attendID,int MeetingID)
        {
            meetingdal.DeleteAttend(attendID,MeetingID);
        }
        //更新与会人员信息
        public int UpdateAttend(attend attend)
        {
            int issuccess = meetingdal.UpdateAttend(attend);
            return issuccess;
        }
        //查看与会人员具体信息
        public attend GetAttendInfo(int AttendID,int MeetingID)
        {
            return meetingdal.GetAttendInfo(AttendID,MeetingID);
        }
        //查看陪同人员
        public List<accompany> GetAccompanyList(int MeetingID,int AttendID)
        {
            return meetingdal.GetAccompanyList(MeetingID,AttendID);
        }
        //删除陪同人员
        public void DeleteAccompany(int attendID, int MeetingID,int AccompanyID)
        {
            meetingdal.DeleteAccompany(attendID, MeetingID,AccompanyID);
        }
        //查看陪同人员具体信息
        public accompany GetAccompanyInfo(int AttendID, int MeetingID,int AccompanyID)
        {
            return meetingdal.GetAccompanyInfo(AttendID, MeetingID,AccompanyID);
        }

        //添加陪同人员
        public int AddAccompany(accompany accompany)
        {
            int issuccess = meetingdal.AddAccompany(accompany);
            return issuccess;
        }

        //更新陪同人员信息
        public int UpdateAccompany(accompany accompany)
        {
            int issuccess = meetingdal.UpdateAccompany(accompany);
            return issuccess;
        }

        //添加子管理员
        public int AddAdmin(Admin admin)
        {
            int issuccess = meetingdal.AddAdmin(admin);
            return issuccess;
        }
        //删除子管理员
        public void DeleteAdmin(int AdminID)
        {
            meetingdal.DeleteAdmin(AdminID);
        }
        //更新子管理员
        public int UpdateAdmin(Admin admin)
        {
            int issuccess = meetingdal.UpdateAdmin(admin);
            return issuccess;
        }
        //查看子管理员
        public List<Admin> GetAllAdminList()
        {
            return meetingdal.GetAllAdminList();
        }
        public Admin GetAdminInfo(int AdminID)
        {
            return meetingdal.GetAdminInfo(AdminID);
        }
        public int GetAdminCount()
        {
            return meetingdal.GetAdminCount();
        }



        //添加宾馆
        public int AddHotel(Hotel hotel)
        {
            int issuccess = meetingdal.AddHotel(hotel);
            return issuccess;
        }
        //删除宾馆
        public void DeleteHotel(string HotelID)
        {
            meetingdal.DeleteHotel(HotelID);
        }
        //更新宾馆
        public int UpdateHotel(Hotel hotel)
        {
            int issuccess = meetingdal.UpdateHotel(hotel);
            return issuccess;
        }
        //查看宾馆
        public List<Hotel> GetAllHotelList()
        {
            return meetingdal.GetAllHotelList();
        }
        public Hotel GetHotelInfo(string HotelID)
        {
            return meetingdal.GetHotelInfo(HotelID);
        }
        public int GetHotelCount()
        {
            return meetingdal.GetHotelCount();
        }


        //添加普通用户
        public int AddOrduser(Orduser ord)
        {
            int issuccess = meetingdal.AddOrduser(ord);
            return issuccess;
        }
        //删除普通用户
        public void DeleteOrduser(int OrduserID)
        {
            meetingdal.DeleteOrduser(OrduserID);
        }
        //更新普通用户
        public int UpdateOrduser(Orduser ord)
        {
            int issuccess = meetingdal.UpdateOrduser(ord);
            return issuccess;
        }
        //查看普通用户
        public List<Orduser> GetAllOrduserList()
        {
            return meetingdal.GetAllOrduserList();
        }
        public Orduser GetOrduserInfo(int OrduserID)
        {
            return meetingdal.GetOrduserInfo(OrduserID);
        }
        public int GetOrduserCount()
        {
            return meetingdal.GetOrduserCount();
        }



        //添加部门
        public int AddDepartment(Department dept)
        {
            int issuccess = int.Parse(meetingdal.AddDepartment(dept));
            return issuccess;
        }
        //删除部门
        public void DeleteDepartment(string DepartmentID)
        {
            meetingdal.DeleteDepartment(DepartmentID);
        }
        //更新部门
        public int UpdateDepartment(Department dept)
        {
            int issuccess = meetingdal.UpdateDepartment(dept);
            return issuccess;
        }
        //查看部门
        public List<Department> GetAllDepartmentList()
        {
            return meetingdal.GetAllDepartmentList();
        }
        public Department GetDepartmentInfo(string DepartmentID)
        {
            return meetingdal.GetDepartmentInfo(DepartmentID);
        }
        public int GetDepartmentCount()
        {
            return meetingdal.GetDepartmentCount();
        }

        //查看某个部门下的所有会议信息
        public List<Meeting> GetDept_MeetingInfo(string DeptID)
        {
            return meetingdal.GetDept_MeetingInfo(DeptID);
        }

        //查看子管理员属于的部门
        public string GetDeptIDfromAdminID(int AdminID)
        {
            return meetingdal.GetDeptIDfromAdminID(AdminID);
        }
    }
}