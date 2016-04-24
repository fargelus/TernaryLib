//#include "datatypes.h"
//#include <QDebug>

// операция сложения двух троичных целых
// чисел
//Trint::Trint()
//{
//    memory.setSize(size);
//}

//Troolean::Troolean(int val)
//{
//    if (val < -364 || val > 364)
//        throw SimpleException("Troolean must be between -364 and 364");
//    if (val > 0)
//        memory.fill(Trit(POS, 0));
//    else if (val == 0)
//        memory.fill(Trit(UNKNOWN, 0));
//    else
//        memory.fill(Trit(NEG, 0));
//}

//Troolean Troolean::operator~()
//{
//    Troolean t;
//    if (memory.get(0).getState() == POS)
//        t.memory.fill(Trit(NEG, 0));
//    else if (memory.get(0).getState() == NEG)
//        t.memory.fill(Trit(POS, 0));
//    return t;
//}

//Troolean Troolean::operator&&(Troolean & t)
//{
//    Troolean tr;
//    if (memory.get(0).getState() == NEG)
//        tr = Troolean(-1);
//    else if (memory.get(0).getState() == POS)
//    {
//        switch(t[0].getState())
//        {
//            case NEG:
//                tr = Troolean(-1);
//                break;
//            case UNKNOWN:
//                tr = Troolean(0);
//                break;
//            case POS:
//                tr = Troolean(1);
//                break;
//            default:
//                break;
//        }
//    }
//    else
//    {
//        switch(t[0].getState())
//        {
//            case NEG:
//                tr = Troolean(-1);
//                break;
//            case UNKNOWN:
//                tr = Troolean(0);
//                break;
//            case POS:
//                tr = Troolean(0);
//                break;
//            default:
//                break;
//        }
//    }

//    return tr;
//}

//Troolean Troolean::operator ||(Troolean & t)
//{
//    Troolean tr;
//    if (memory.get(0).getState() == POS)
//        tr = Troolean(1);
//    else if (memory.get(0).getState() == NEG)
//    {
//        switch(t[0].getState())
//        {
//            case NEG:
//                tr = Troolean(-1);
//                break;
//            case UNKNOWN:
//                tr = Troolean(0);
//                break;
//            case POS:
//                tr = Troolean(1);
//                break;
//            default:
//                break;
//        }
//    }
//    else
//    {
//        switch(t[0].getState())
//        {
//            case NEG:
//                tr = Troolean(0);
//                break;
//            case UNKNOWN:
//                tr = Troolean(0);
//                break;
//            case POS:
//                tr = Troolean(1);
//                break;
//            default:
//                break;
//        }
//    }

//    return tr;
//}

//void Troolean::display()
//{
//    Tryte::display();
//}

//std::ostream& operator<<(std::ostream & out, Troolean & t)
//{
//    if (t.memory.get(0).getState() == NEG)
//        out << "false";
//    else if (t.memory.get(0).getState() == POS)
//        out << "true";
//    else
//        out << "unknown";
//    return out;
//}



