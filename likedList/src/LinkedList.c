#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){
	LinkedList* this;
	this = (LinkedList*)malloc(sizeof(LinkedList*));
	if(this != NULL){
		this->pFirstNode = 0;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){
	int retorno = -1;
	if(this != NULL){
		 retorno =  this->size;
	}
	return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex){
	Node* auxNode = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
    	auxNode = this->pFirstNode;
    	for(int i = 0; i < nodeIndex; i++){
    		auxNode = auxNode->pNextNode;
    	}
    }
    return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int retorno = -1;
    Node* auxNode = (Node*)malloc(sizeof(Node*));
    Node* auxPrevNode = NULL;

    if(auxNode != NULL && this != NULL && nodeIndex >= 0 && pElement != NULL && nodeIndex<=ll_len(this)){
    	auxNode->pElement = pElement;
    	if(nodeIndex == 0){
    		auxNode->pNextNode = this->pFirstNode;
    		this->pFirstNode = auxNode;
    		this->size++;
    		retorno = 0;
    	} else{
    		auxPrevNode = getNode(this, nodeIndex-1);
    		if(auxPrevNode != NULL){
    			auxNode->pNextNode = auxPrevNode->pNextNode;
    			auxPrevNode->pNextNode = auxNode;
    			this->size++;
    			retorno = 0;
    		}
    	}
    }
    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){
	int retorno = -1;
	if(this != NULL && pElement != NULL){
		if(addNode(this, ll_len(this), pElement) == 0){
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index){
	Node* auxNode = NULL;
	void* pRetorno = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this)){
		auxNode = getNode(this, index);
		if(auxNode != NULL){
			pRetorno = auxNode->pElement;
		}
	}
	return pRetorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement){
	int retorno = -1;
	Node* auxNode = NULL;
	if(this != NULL && pElement != NULL && index >= 0 && index < ll_len(this)){
		auxNode = getNode(this, index);
		auxNode->pElement = pElement;
		retorno = 0;
	}
	return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index){
	int retorno = -1;
	Node* auxNode = NULL;
	Node* auxPrevNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this)){
		auxNode = getNode(this, index);
		if(index == 0){
			this->pFirstNode = auxNode->pNextNode;
			this->size--;
		} else{
			//VER
			auxPrevNode = getNode(this, index-1);
			auxPrevNode->pNextNode = auxNode->pNextNode;
			this->size--;
		}
		free(auxNode);
		retorno = 0;
	}
	return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this){
	int retorno = -1;
	int len = ll_len(this);
	if(this != NULL && len > 0){
		for(int i = 0; i < len; i++){
			ll_remove(this, 0);
		}
		retorno = 0;
	}
	return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this){
	int retorno = -1;
	if(this != NULL){
		ll_clear(this);
		free(this);
		retorno = 0;
	}
	return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement){
	int retorno = -1;
	int len = ll_len(this);
	Node* auxNode;
	if(this != NULL && pElement != NULL){
		for(int i = 0; i < len; i++){
			auxNode = getNode(this, i);
			if(auxNode != NULL && auxNode->pElement == pElement){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this){
    int retorno = -1;//null
    if(this != NULL){
    	if(ll_len(this) > 0){
    		retorno = 0;//no vacia
    	} else{
    		retorno = 1;//vacia
    	}
    }
    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement){
	int retorno = -1;
	int len = ll_len(this);
	if(this != NULL && pElement != NULL && index >= 0 && index <= len){
		if( addNode(this, index, pElement) == 0){
			retorno = 0;
		}
	}
	return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index){
	void* retorno = NULL;
	void* auxPElement = NULL;
	int len = ll_len(this);
	if(this != NULL && index >= 0 && index <= len){
		auxPElement = ll_get(this, index);
		if(auxPElement != NULL){
			retorno = auxPElement;
			ll_remove(this, index);
		}
	}
	return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){
    int retorno = -1;
    if(this != NULL && pElement != NULL){
    	if(ll_indexOf(this, pElement) != -1){
    		//si contiene
    		retorno = 0;
    	} else{
    		//no contiene
    		retorno = 1;
    	}
    }
    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2){
	int retorno = -1;
	int len;
	if(this != NULL && this2 != NULL){
		len = ll_len(this2);
		if(len == 0){
			retorno = 0;
		} else{
			for(int i = 0; i < len; i++){
				if(ll_contains(this, ll_get(this2, i)) == 0){
					retorno = 0;
					break;
					//no contiene
				} else{
					retorno = 1;
					//contiene
				}
			}
		}
	}
	return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to){
   LinkedList* subList;
   void* auxPElement;
   if(this != NULL && to > from && to <= ll_len(this) && from >= 0 && from < ll_len(this)){
	   subList = ll_newLinkedList();
	   if(subList != NULL){
		   for(int i = from; i < to; i++){
			   auxPElement = ll_get(this, i);
			   if(auxPElement != NULL){
				   ll_add(this, auxPElement);
			   }
		   }
	   }
   }
   return subList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){
	LinkedList* cloneList = NULL;
	if(this != NULL){
		cloneList = ll_subList(this, 0, ll_len(this));

	}
	return cloneList;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
	int returnAux = -1;
	int estaOrdenado;
	int len;
	void *auxElement = NULL;
	void *auxElementDos = NULL;
	int retornoPFunc;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {

		len = ll_len(this);

		do {
			estaOrdenado = 1;
			len--;
			for (int i = 0; i < len; i++) {

				auxElement = ll_get(this, i);
				auxElementDos = ll_get(this, i + 1);
				retornoPFunc = pFunc(auxElement, auxElementDos);

				//2, 4, 6, 8
				//para arriba

				if ((retornoPFunc > 0 && order == 1)
						|| (retornoPFunc < 0 && order == 0)) {
					ll_set(this, i, auxElementDos);
					ll_set(this, i + 1, auxElement);
					estaOrdenado = 0;
				}

			}

		} while (estaOrdenado == 0);

		returnAux = 0;
	}

	return returnAux;

	}


LinkedList* ll_filter(LinkedList* this, int (fn)(void* element)){
    LinkedList *filterList=NULL;
    int lenList;
    void *auxElement;

    if(this != NULL && fn != NULL)
    {
        filterList=ll_newLinkedList();

        lenList=ll_len(this);//INDEX DE ULTIMO ELEMENTO VA A SER MENOR AL TOTAL DE LOS ELEMENTOS.N-1
        if(filterList != NULL && lenList>0)
        {
          for(int i=0;i<lenList;i++)
          {
            auxElement=ll_get(this,i);

            if(auxElement != NULL && fn(auxElement)==1)
            {
             ll_add(filterList, auxElement);
            }
          }
        }
    }
    return filterList;
}


LinkedList* ll_map(LinkedList* this, void (fn)(void* element)){
    int lenList;
    void *auxElement;

    if(this != NULL && fn != NULL)
    {
        lenList=ll_len(this);//INDEX DE ULTIMO ELEMENTO VA A SER MENOR AL TOTAL DE LOS ELEMENTOS.N-1
        if(lenList>0)
        {
          for(int i=0;i<lenList;i++)
          {
            auxElement=ll_get(this,i);

            if(auxElement != NULL)
            {
                fn(auxElement);
            }
          }


        }



    }

    return this;
}

//ll_Count
int ll_Count(LinkedList* this, int (*pFunc)(void*)){
	int contador = 0;
	int len;
	void* auxElement;

	if(this != NULL && pFunc != NULL){
		len = ll_len(this);
		if(len > 0){
			for(int i = 0; i < len; i++){
				auxElement = ll_get(this, i);
				if(auxElement != NULL && pFunc(auxElement) == 1){
					contador++;
				}
			}
		}
	}
	return contador;
}
