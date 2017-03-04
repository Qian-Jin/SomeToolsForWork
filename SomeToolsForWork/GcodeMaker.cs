using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools
{
    class GcodeMaker
    {
        private const double for_time = 99;
        private const double for_step = 1;

        public enum typ_xy
        {
            X,
            Y
        };

        public static string OneGcode = "";//一条字符串
        public static string ProGcode = "";//程序G代码

  
        //输出G代码到文件
        public static void GcodeOutput()
        {
            FileStream GcodeFile = new FileStream(@"E:\TextOut\Gcode.txt", FileMode.Create, FileAccess.Write, FileShare.Read);
            FileStream[] GcodePro =
            {
                new FileStream(@"E:\TextOut\GcodePro0.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro1.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro2.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro3.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro4.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro5.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro6.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro7.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro8.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro9.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro10.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro11.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro12.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro13.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro14.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro15.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro16.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro17.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro18.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro19.txt", FileMode.Create, FileAccess.Write, FileShare.Read),
                new FileStream(@"E:\TextOut\GcodePro20.txt", FileMode.Create, FileAccess.Write, FileShare.Read)
           };

            ProGcode = "IF NC_START & (SysCNC[8].FileStartOffset<204800) & (NOT outline) THEN\n";
            ProGcode = ProGcode + "\tSysCNC[8].StoreFilePtr := ADR((SysCNC[8].DATA[1]));\n\n";
            for (int i = 0; i <= 20 ; i++)
            {
                AddText(GcodePro[i], ProGcode);
            }

            var linenum = -1;
            var countline = 0;
            var datasize = 0;
            for (double i = 0; i <= for_time; i = i + for_step)
            {
                if(false) //(i == 0)
                {
                    OneGcode = "N0 G51 D3";

                }
                else
                {
                    
                    linenum++;
                    if (linenum >=10)
                    {
                        linenum = 0;
                    }
                    OneGcode = "N" + Convert.ToString(linenum) + " " + "G1 " + "X" + Convert.ToString(Outputfun(i, typ_xy.X)) + " " + "Y" + Convert.ToString(Outputfun(i, typ_xy.Y));
                    if(false) //(linenum == 1)
                    {
                        OneGcode = OneGcode + " E3 E-2 F5";
                    }
                    else
                    {
                        OneGcode = OneGcode + "";
                    }
                }
                AddText(GcodeFile, OneGcode+"\n");


                ProGcode = "\t" + "IF NC_CurrentLine = " + Convert.ToString(countline) + " + offset*100 THEN\n";

                ProGcode = ProGcode + "\t" + "\tSysCNC[8].FileStartOffset := " + Convert.ToString(datasize) + "+ offset*1100;\n";

                ProGcode = ProGcode + "\t" + "\tString1 := '" + OneGcode + "';\n";
                ProGcode = ProGcode + "\t" + "\tFOR i:=0 TO " + Convert.ToString(OneGcode.Length) + " BY 1 DO\n";
                ProGcode = ProGcode + "\t" + "\t\tnum[i] := SINT_TO_USINT(String1[i+1]);\n";
                ProGcode = ProGcode + "\t" + "\tEND_FOR;\n";
                ProGcode = ProGcode + "\t" + "\tFOR k:=0 TO " + Convert.ToString(OneGcode.Length) + " BY 1 DO\n";
                ProGcode = ProGcode + "\t" + "\t\t(SysCNC[8].StoreFilePtr+SysCNC[8].FileStartOffset+k)^ := num[k];\n";
                ProGcode = ProGcode + "\t" + "\tEND_FOR;\n";
                ProGcode = ProGcode + "\t" + "\tSysCNC[8].TotalLineNum := " + Convert.ToString(countline + 1) + " + offset*101;\n";
                datasize = datasize + OneGcode.Length;

                if (datasize > 200 * 1024)
                {
                    datasize = 0;
                }

                ProGcode = ProGcode + "\t" + "END_IF;\n\n";

                if (i / 1000 < 20)
                {
                    AddText(GcodePro[((int)(i / 1000))], ProGcode);
                }

                countline++;
            }

            ProGcode = "END_IF;\n\n";
            for (int i = 0; i <= 20; i++)
            {
                AddText(GcodePro[i], ProGcode);
            }

            for (int i = 0; i <= 20; i++)
            {
                GcodePro[i].Close();
            }

            GcodeFile.Close();

        }

        //加入字符
        private static void AddText(FileStream fs, string value)
        {
            byte[] info = new UTF8Encoding(true).GetBytes(value);
            fs.Write(info, 0, info.Length);
        }

        //总输出函数
        public static double Outputfun(double i,typ_xy xy)
        {
            switch (xy)
            {
                case typ_xy.X:
                    return f_oneway(i, typ_xy.X);
                case typ_xy.Y:
                    return f_oneway(i, typ_xy.Y);
                default:
                    return -1;
            }
        }

        //各个函数

        //仅一个方向
        public static double f_oneway(double i, typ_xy typ)
        {
            switch (typ)
            {
                case typ_xy.X:
                    /*if (((int)i) % 2==0)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }*/
                    return (((int)i) % 10);
                case typ_xy.Y:
                    return 0;
                default:
                    return -1;
            }
        }
    }
}
