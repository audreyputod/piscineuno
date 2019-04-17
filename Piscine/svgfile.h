///Fichier donnée par Mr.Fercoq dans les TP
///Ajout Gradient,Polygone,Polyline,Ellipse
///DETOURNAY-HILT-PICHON
#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED

#include <string>
#include <fstream>
#include <set>
#include <vector>


constexpr char defcol[] = "black";


class Svgfile
{
    public:
        Svgfile(std::string _filename = "output.svg", int _width=800, int _height=800);
        ~Svgfile();


        void addCircle(double x, double y, double r, double ep, std::string color=defcol);
        void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
        void addText(double x, double y, std::string text, std::string color=defcol);
        void addText(double x, double y, double val, std::string color=defcol);

        static std::string makeRGB(int r, int g, int b);


        /// Type non copiable
        Svgfile(const Svgfile&) = delete;
        Svgfile& operator=(const Svgfile&) = delete;

    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour Ã©viter les ouverture multiples
        static std::set<std::string> s_openfiles;
};



std::string fillBallColor(std::string col);

#endif // SVGFILE_H_INCLUDED



