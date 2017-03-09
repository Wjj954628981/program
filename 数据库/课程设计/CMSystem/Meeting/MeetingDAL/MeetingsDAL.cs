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
        public int AddMeeting(Meetings meeting)
        {
            using (Model1Container ef=new Model1Container())
            {
                ef.Meetings.AddObject(meeting);
                return ef.SaveChanges();
            }
        }
        //删除会议
        public void DeleteMeeting(string MeetingMId)
        {
            using (Model1Container ef=new Model1Container())
            {
                Meetings meeting=ef.Meetings.Where(item=>item.m_id==MeetingMId).FirstOrDefault();
                ef.DeleteObject(meeting);
                ef.SaveChanges();
            }
        }
        //更改会议
        public int UpdateMeeting(Meetings meeting)
        {
            using (Model1Container ef=new Model1Container())
            {
                ef.Meetings.Attach(meeting);
                ef.ObjectStateManager.ChangeObjectState(meeting,EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //查看全部会议
        public List<Meetings>GetAllMeetingList()
        {
            using (Model1Container ef=new Model1Container())
            {
                List<Meetings> result=ef.Meetings.ToList();
                return result.OrderByDescending(item=>item.m_id).ToList();
            }
        }

        //获取某一会议具体信息
        public  Meetings GetMeetingInfo(string MeetingMId)
        {
            using (Model1Container ef=new Model1Container())
            {
                return ef.Meetings.Where(item=>item.m_id==MeetingMId).FirstOrDefault();
            }
        }
        //获取全部会议总数
        public int GetMeetingCount()
        {
            using (Model1Container ef=new Model1Container())
            {
                return ef.Meetings.Count();
            }
        }
    }
}