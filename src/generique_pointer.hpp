//
// Created by dadou on 19/03/15.
//

#ifndef _GARBAGE_COLLECTOR_GENERIQUE_POINTER_HPP_
#define _GARBAGE_COLLECTOR_GENERIQUE_POINTER_HPP_

#include <iostream>

/** \brief general behavior of a smart pointer
 */
class generique_pointer {

    public :

        friend class garbage_collector;

        generique_pointer() : id(generique_pointer::inc_compteur()) {};

        virtual ~generique_pointer() {};

        virtual void force_detach() = 0;

        /** \brief return egality on generics pointers on their id attribute
         */
        inline bool operator ==(const generique_pointer &rhs) const {
                return (this->id == rhs.id);
        };

        /** \brief compare two generics pointers on their id attributes
         *
         */
        inline bool operator <(const generique_pointer &rhs) const {
                return (this->id < rhs.id);
        };

        virtual void * get_addr() const {
            #ifdef DEBUG
                std::cerr << "virtual void * generique_pointer::get_addr() const" << std::endl;
            #endif
            return NULL;
        };


        static long inc_compteur();

private :
        long static long_auto_inc;
        long id; /**< represent identity */
};

#endif //_GARBAGE_COLLECTOR_GENERIQUE_POINTER_HPP_
