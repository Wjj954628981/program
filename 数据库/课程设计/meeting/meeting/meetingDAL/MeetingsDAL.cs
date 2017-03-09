using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.Entity;
using MeetingModel;

namespace MeetingDAL
{
    public class MeetingsDAL
    {
        //添加会议
        public int AddMeeting(Meeting meeting)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Meeting.AddObject(meeting);
                return ef.SaveChanges();
            }
        }
        //删除会议
        public void DeleteMeeting(int MeetingID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                Meeting meeting = ef.Meeting.Where(item => item.m_id == MeetingID).FirstOrDefault();
                ef.Meeting.DeleteObject(meeting);
                ef.SaveChanges();
            }
        }
        //更改会议
        public int UpdateMeeting(Meeting meeting)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Meeting.Attach(meeting);
                ef.ObjectStateManager.ChangeObjectState(meeting, System.Data.Entity.EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //查看会议
        public List<Meeting> GetAllMeetingList()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<Meeting> result = ef.Meeting.ToList();
                return result.OrderByDescending(item => item.m_id).ToList();
            }
        }
        //查看会议具体信息
        public Meeting GetMeetingInfo(int MeetingID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Meeting.Where(item => item.m_id == MeetingID).FirstOrDefault();
            }
        }
        public int GetMeetingCount()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Meeting.Count();
            }
        }
        
        //查看与会人员
        public List<attend> GetAttendList(int MeetingID)
        {
            using(MeetingModelContainer ef=new MeetingModelContainer())
            {
                List<attend> result = ef.attend.Where(item => item.m_id == MeetingID).ToList();
                return result.OrderByDescending(item => item.m_id).ToList();
            }
        }

        //添加与会人员
        public int AddAttend(attend attend)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.attend.AddObject(attend);
                return ef.SaveChanges();
            }
        }
        //删除与会人员
        public void DeleteAttend(int AttendID,int MeetingID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                //attend attend = ef.attend.Where(item => item.participator_id == AttendID).FirstOrDefault();
                List<attend> result = ef.attend.Where(item => item.participator_id == AttendID).ToList();
                attend attend=result.Where(item => item.m_id == MeetingID).FirstOrDefault();
                ef.attend.DeleteObject(attend);
                ef.SaveChanges();
            }
        }
        //更改会议人员信息
        public int UpdateAttend(attend attend)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.attend.Attach(attend);
                ef.ObjectStateManager.ChangeObjectState(attend, System.Data.Entity.EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //查看与会人员具体信息
        public attend GetAttendInfo(int AttendID,int MeetingID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<attend> result = ef.attend.Where(item => item.participator_id == AttendID).ToList();
                return result.Where(item => item.m_id == MeetingID).FirstOrDefault();
            }
        }

        //查看陪同人员
        public List<accompany> GetAccompanyList(int MeetingID,int AttendID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<accompany> result = ef.accompany.Where(item => item.m_id == MeetingID).ToList();
                result=result.Where(item => item.participator_id == AttendID).ToList();
                return result.OrderByDescending(item => item.m_id).ToList();
            }
        }

        //删除陪同人员
        public void DeleteAccompany(int AttendID, int MeetingID, int AccompanyID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                //attend attend = ef.attend.Where(item => item.participator_id == AttendID).FirstOrDefault();
                List<accompany> result = ef.accompany.Where(item => item.participator_id == AttendID).ToList();
                List<accompany> result2 = result.Where(item => item.m_id == MeetingID).ToList();
                accompany accompany = result2.Where(item => item.re_id == AccompanyID).FirstOrDefault();
                ef.accompany.DeleteObject(accompany);
                ef.SaveChanges();
            }
        }

        //查看与会人员具体信息
        public accompany GetAccompanyInfo(int AttendID, int MeetingID,int AccompanyID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<accompany> result = ef.accompany.Where(item => item.participator_id == AttendID).ToList();
                List<accompany> result2 = result.Where(item => item.m_id == MeetingID).ToList();
                return result2.Where(item => item.re_id == AccompanyID).FirstOrDefault();
            }
        }

        //添加陪同人员
        public int AddAccompany(accompany accompany)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.accompany.AddObject(accompany);
                return ef.SaveChanges();
            }
        }

        //更改陪同人员信息
        public int UpdateAccompany(accompany accompany)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.accompany.Attach(accompany);
                ef.ObjectStateManager.ChangeObjectState(accompany, System.Data.Entity.EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //增加子管理员
        public int AddAdmin(Admin admin)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Admin.AddObject(admin);
                return ef.SaveChanges();
            }
        }
        //删除子管理员
        public void DeleteAdmin(int AdminID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                Admin admin = ef.Admin.Where(item => item.id == AdminID).FirstOrDefault();
                ef.Admin.DeleteObject(admin);
                ef.SaveChanges();
            }
        }
        //更改子管理员
        public int UpdateAdmin(Admin admin)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Admin.Attach(admin);
                ef.ObjectStateManager.ChangeObjectState(admin, System.Data.Entity.EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //查看子管理员
        public List<Admin> GetAllAdminList()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<Admin> result = ef.Admin.ToList();
                return result.OrderByDescending(item => item.id).ToList();
            }
        }
        //查看子管理员具体信息
        public Admin GetAdminInfo(int AdminID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Admin.Where(item => item.id == AdminID).FirstOrDefault();
            }
        }
        public int GetAdminCount()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Admin.Count();
            }
        }


        //增加宾馆
        public int AddHotel(Hotel hotel)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Hotel.AddObject(hotel);
                return ef.SaveChanges();
            }
        }
        //删除宾馆
        public void DeleteHotel(String HotelID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                Hotel hotel = ef.Hotel.Where(item => item.h_name == HotelID).FirstOrDefault();
                ef.Hotel.DeleteObject(hotel);
                ef.SaveChanges();
            }
        }
        //更改宾馆
        public int UpdateHotel(Hotel hotel)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Hotel.Attach(hotel);
                ef.ObjectStateManager.ChangeObjectState(hotel, System.Data.Entity.EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //查看宾馆
        public List<Hotel> GetAllHotelList()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<Hotel> result = ef.Hotel.ToList();
                return result.OrderByDescending(item => item.h_name).ToList();
            }
        }
        //查看宾馆具体信息
        public Hotel GetHotelInfo(string HotelID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Hotel.Where(item => item.h_name == HotelID).FirstOrDefault();
            }
        }
        public int GetHotelCount()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Hotel.Count();
            }
        }


        //增加普通用户
        public int AddOrduser(Orduser ord)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Orduser.AddObject(ord);
                return ef.SaveChanges();
            }
        }
        //删除普通用户
        public void DeleteOrduser(int OrduserID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                Orduser ord = ef.Orduser.Where(item => item.id == OrduserID).FirstOrDefault();
                ef.Orduser.DeleteObject(ord);
                ef.SaveChanges();
            }
        }
        //更改普通用户
        public int UpdateOrduser(Orduser ord)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Orduser.Attach(ord);
                ef.ObjectStateManager.ChangeObjectState(ord, System.Data.Entity.EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //查看普通用户
        public List<Orduser> GetAllOrduserList()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<Orduser> result = ef.Orduser.ToList();
                return result.OrderByDescending(item => item.id).ToList();
            }
        }
        //查看普通用户具体信息
        public Orduser GetOrduserInfo(int OrduserID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Orduser.Where(item => item.id == OrduserID).FirstOrDefault();
            }
        }
        public int GetOrduserCount()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Orduser.Count();
            }
        }




        //增加部门
        public string AddDepartment(Department dept)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Department.AddObject(dept);
                return ef.SaveChanges().ToString();
            }
        }
        //删除部门
        public void DeleteDepartment(string DepartmentID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                Department dept = ef.Department.Where(item => item.dept_id == DepartmentID).FirstOrDefault();
                ef.Department.DeleteObject(dept);
                ef.SaveChanges();
            }
        }
        //更改部门
        public int UpdateDepartment(Department dept)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.Department.Attach(dept);
                ef.ObjectStateManager.ChangeObjectState(dept, System.Data.Entity.EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //查看部门
        public List<Department> GetAllDepartmentList()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<Department> result = ef.Department.ToList();
                return result.OrderByDescending(item => item.dept_id).ToList();
            }
        }
        //查看部门具体信息
        public Department GetDepartmentInfo(string DepartmentID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Department.Where(item => item.dept_id == DepartmentID).FirstOrDefault();
            }
        }
        public int GetDepartmentCount()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Department.Count();
            }
        }


        //查看某个部门下的所有会议信息
        public List<Meeting> GetDept_MeetingInfo(string DeptID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.Meeting.Where(item => item.dept_id == DeptID).ToList();
            }
        }

        //查看子管理员属于的部门
        public string GetDeptIDfromAdminID(int AdminID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                Admin result = ef.Admin.Where(item => item.id == AdminID).FirstOrDefault();
                return result.dept_id;
            }
        }
    }

}