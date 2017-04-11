using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linq
{
    public class City
    {
        public String city_name { get; set; }
        public int Population { get; set; }

    }
    class Program
    {
        static void Main(string[] args)
        {
            City Tianjin = new City() { city_name = "Tianjin", Population = 1000 };
            City Beijing = new City() { city_name = "Beijing", Population = 3000 };
            City Shanghai = new City() { city_name = "Shanghai", Population = 3000 };
            City Hangzhou = new City() { city_name = "Hangzhou", Population = 4000 };
            City[] citys = { Tianjin, Beijing, Shanghai, Hangzhou };

            //查詢語法
            var percentileQuery =
                from city in citys
                let percentile = city.Population / 1000
                group city by percentile into cityGroup
                where cityGroup.Key >= 2
                orderby cityGroup.Key
                select cityGroup;
            foreach (var grouping in percentileQuery)
            {
                //混合語法Count()
                Console.WriteLine(grouping.Key + "k萬的城市有" + grouping.Count() + "個，分別是：");
                foreach (var city in grouping)
                    Console.WriteLine(city.city_name + ":" + city.Population);
            }

            Console.WriteLine();

            //方法語法
            IEnumerable<City> Query = citys.Where(city => city.Population >= 2000);
            foreach (City city in Query)
            {
                Console.WriteLine(city.city_name);
            }
            Console.ReadLine();
        }
    }
}
