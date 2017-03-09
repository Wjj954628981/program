using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MeetingDAL;
using MeetingModel;

namespace MeetingBLL
{
    public class AgendaBLL
    {
        AgendaDAL agendadal = new AgendaDAL();
        //添加日程
        public int AddAgenda(agenda agenda)
        {
            int issuccess = agendadal.AddAgenda(agenda);
            return issuccess;
        }
        //删除日程
        public void DeleteAgenda(int agendanumber)
        {
            agendadal.DeleteAgenda(agendanumber);
        }
        //更新日程
        public int UpdateAgenda(agenda agenda)
        {
            int issuccess = agendadal.UpdateAgenda(agenda);
            return issuccess;
        }
        //查看日程
        public List<agenda> GetAgendaList(int MID)
        {
            return agendadal.GetAgendaList(MID);
        }
        public agenda GetAgendaInfo(int agendanumber)
        {
            return agendadal.GetAgendaInfo(agendanumber);
        }
        public int GetAgendaCount()
        {
            return agendadal.GetAgendaCount();
        }
    }
}