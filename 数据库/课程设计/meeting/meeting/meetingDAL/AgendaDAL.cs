using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using MeetingModel;
using System.Data.Entity;
namespace MeetingDAL
{
    public class AgendaDAL
    {
        //查看日程
        public List<agenda> GetAgendaList(int MID)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                List<agenda> result = ef.agenda.Where(item => item.m_id == MID).ToList();
                return result.OrderByDescending(item => item.m_id).ToList();
            }
        }
        //添加日程
        public int AddAgenda(agenda agenda)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.agenda.AddObject(agenda);
                return ef.SaveChanges();
            }
        }
        //删除会议
        public void DeleteAgenda(int agendanumber)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                agenda agenda = ef.agenda.Where(item => item.agenda_number == agendanumber).FirstOrDefault();
                ef.agenda.DeleteObject(agenda);
                ef.SaveChanges();
            }
        }
        //更改日程
        public int UpdateAgenda(agenda agenda)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                ef.agenda.Attach(agenda);
                ef.ObjectStateManager.ChangeObjectState(agenda, System.Data.Entity.EntityState.Modified);
                return ef.SaveChanges();
            }
        }
        //查看日程具体信息
        public agenda GetAgendaInfo(int agendanumber)
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.agenda.Where(item => item.agenda_number == agendanumber).FirstOrDefault();
            }
        }
        public int GetAgendaCount()
        {
            using (MeetingModelContainer ef = new MeetingModelContainer())
            {
                return ef.agenda.Count();
            }
        }
    }
}