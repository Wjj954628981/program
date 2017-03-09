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
        //创建MeetingDAL对象
        MeetingsDAL meetingdal=new MeetingsDAL();

        //添加会议
        public int AddMeeting(Meetings meeting)
        {
            int issuccess=meetingdal.AddMeeting(meeting);
            return issuccess;
        }

        //删除会议
        public void DeleteMeeting(string MeetingMId)
        {
            meetingdal.DeleteMeeting(MeetingMId);
        }

        //更改会议
        public int UpdateMeeting(Meetings meeting)
        {
            int issuccess=meetingdal.UpdateMeeting(meeting);
            return issuccess;
        }

        //查看全部会议
        public List<Meetings>GetAllMeetingList()
        {
            return meetingdal.GetAllMeetingList();
        }

        //获取某一会议具体信息
        public Meetings GetMeetingInfo(string MeetingMId)
        {
            return meetingdal.GetMeetingInfo(MeetingMId);
        }
        //获取全部会议总数
        public int GetMeetingCount()
        {
            return meetingdal.GetMeetingCount();
        }
    }
}
