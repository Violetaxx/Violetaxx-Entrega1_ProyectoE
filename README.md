# Violetaxx-Entrega1_ProyectoE
 Componente 1: Proyección de imágenes
 Objetivo: A partir de una serie ordenada de imágenes que conforman un volumen 3D, construir la proyección
 del volumen hacia un plano de acuerdo a una dirección y a un criterio de proyección, utilizando estructuras
 lineales.
 La proyección de imágenes tridimensionales hace referencia a la generación de una representación planar
 (2D) de un objeto o escena 3D. Un tipo particular de proyección es comúnmente utilizado para la producción
 de radiografías. En este caso, el objeto a visualizar es bombardeado por una serie de rayos X, paralelos entre
 sí y perpendiculares a la superficie de captura. La cantidad de energía del rayo que alcanza a atravesar el
 objeto se refleja en la superficie de captura, donde queda plasmada la imagen de la proyección. Este proceso
 se ilustra en la Figura 2.
 De esta forma, el componente 1 del sistema corresponderá a una simulación del proceso de captura
 de radiografías. Para esto, se recibirá una serie ordenada de imágenes 2D, es decir, una conjunto de
 imágenes que juntas (en un orden específico) representan una escena 3D. Luego, se simulará el proceso de
 proyección analizando linealmente la información del volumen en una dirección específica, es decir, colapsando
 2
Figure 2: Ilustración del proceso de generación de una proyección planar por medio de rayos X (Tomado de
 http://www.sv.vt.edu/classes/ESM4714/methods/FuncExt.html)
 la información contenida en cada una de las filas del volumen en un único píxel. Esto generará una proyección
 2D de la imagen volumétrica en la dirección especificada. El componente se implementará con los siguientes
 comandos:
 
 • COMANDO(VIOLETA): cargar_imagen nombre_imagen.pgm
 posibles salidas en pantalla:
 (proceso satisfactorio) La imagen nombre_imagen.pgm ha sido cargada.
 (mensaje de error) La imagen nombre_imagen.pgm no ha podido ser cargada.
 descripción: El comando debe cargar en memoria (en la estructura más adecuada) la imagen identificada
 con el nombre_imagen.pgm. Una vez cargada la información en memoria, el comando debe mostrar el
 mensaje de carga satisfactoria. Si por alguna razón no es posible cargar la imagen (nombre de archivo
 erróneo o no existe), el comando debe mostrar el mensaje de error. Solo es posible cargar una única
 imagen por sesión, de tal forma que si el comando es llamado nuevamente con otro nombre de archivo,
 la nueva imagen sobreescribe en memoria a la que ya estaba cargada anteriormente.
 
 • COMANDO: cargar_volumen nombre_base n_im
 salida en pantalla:
 (proceso satisfactorio) El volumen nombre_base ha sido cargado.
 (mensaje de error) El volumen nombre_base no ha podido ser cargado.
 descripción: El comando debe cargar en memoria (en la estructura más adecuada) la serie ordenada de
 imágenes identificada con el nombre_base y cuyo tamaño corresponde a n_im imágenes (la serie
 podrá tener máximo 99 imágenes). Todas las imágenes de la serie deben estar nombradas como
 nombre_basexx.pgm, donde xx corresponde a dos dígitos de identificación de la posición de la imagen
 en la serie (varía en el rango 01- n_im ). Una vez cargada toda la información en memoria, el comando
 debe mostrar el mensaje de carga satisfactoria. Si por alguna razón no es posible cargar completamente
 la serie ordenada de imágenes (nombre de base erróneo, cantidad de imágenes no corresponde, error en
 alguna imagen), el comando debe mostrar el mensaje de error. Solo es posible cargar un único volumen
 por sesión, de tal forma que si el comando es llamado nuevamente con otro nombre base, el nuevo
 volumen sobreescribe en memoria al que ya estaba cargado anteriormente.
 
 • COMANDO(VIOLETA): info_imagen
 salida en pantalla:
 (proceso satisfactorio) Imagen cargada en memoria: nombre_imagen.pgm, ancho: W, alto:
 H.
 (mensaje de error) No hay una imagen cargada en memoria.
 descripción: El comando debe mostrar en pantalla la información básica de la imagen actualmente
 cargada en memoria: nombre de archivo, ancho en pixeles y alto en pixeles. Si no se ha cargado aún
 una imagen en memoria, el comando debe mostrar el mensaje de error.
 
 • COMANDO(VIOLETA): info_volumen
 salida en pantalla:
 3
(proceso satisfactorio) Volumen cargado en memoria: nombre_base, tamaño: n_im, ancho:
 W, alto: H.
 (mensaje de error) No hay un volumen cargado en memoria.
 descripción: El comando debe mostrar en pantalla la información básica del volumen (serie de imágenes)
 cargado actualmente en memoria: nombre base, cantidad de imágenes, ancho en pixeles y alto en pixeles.
 Si no se ha cargado aún un volumen en memoria, el comando debe mostrar el mensaje de error.
 
 • COMANDO: proyeccion2D dirección criterio nombre_archivo.pgm
 salida en pantalla:
 (proceso satisfactorio) La proyección 2D del volumen en memoria ha sido generada y almacenada
 en el archivo nombre_archivo.pgm.
 (mensajes de error)
 El volumen aún no ha sido cargado en memoria.
 La proyección 2D del volumen en memoria no ha podido ser generada.
 descripción: El comando debe tomar la serie ordenada de imágenes (ya cargada en memoria), y de
 acuerdo a la dirección especificada por el usuario, debe recorrer cada posición en el plano perpendicular
 a la dirección dada, y para cada una de esas posiciones debe colapsar toda la información existente en la
 dirección dada utilizando el criterio especificado. Esto genera un único valor de píxel para cada posición
 del plano perpendicular, generando así una imagen 2D con la proyección de la información en el volumen.
 La dirección puede ser una entre x (en dirección de las columnas), y (en dirección de las filas) o z (en
 dirección de la profundidad). El criterio puede ser uno entre minimo (el valor mínimo de intensidad),
 maximo (el valor máximo de intensidad), promedio (el valor promedio de intensidad) o mediana (el
 valor mediana de intensidad). Una vez generada la proyección, debe guardarse como imagen en formato
 PGMcomo nombre_archivo.pgm. Es importante anotar que este comando solo puede funcionar sobre
 volúmenes (series de imágenes). La Figura 3 ilustra el proceso de proyección en cada una de las posibles
 direcciones.
