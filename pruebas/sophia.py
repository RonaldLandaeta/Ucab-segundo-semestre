import tkinter as tk
from tkinter import messagebox

def calcular_total():
    try:
        nombre = entrada_nombre.get().strip()
        
        if not nombre:
            messagebox.showwarning("Aviso", "Por favor, introduza algun nonbre para el cliente.")
            return
        
        precios = []
        for entrada in entradas_precios:
            valor_texto = entrada.get().strip()
            if not valor_texto:
                messagebox.showwarning("Aviso", "Por favor, introducir minimo 5 prodctos.")
                return
                
            valor_num = float(valor_texto)
            if valor_num < 0:
                messagebox.showwarning("Aviso", "Los precios no pueden ser negativos.")
                return
                
            precios.append(valor_num)
        subtotal = sum(precios)
        #IVA (ex: 16%)
        tasa_iva = 0.16 
        iva_total = subtotal * tasa_iva # (Requisito A)
        total_pagar = subtotal + iva_total # (Requisito B)
        lbl_subtotal_res.config(text=f"${subtotal:.2f}")
        lbl_iva_res.config(text=f"${iva_total:.2f}")
        lbl_total_res.config(text=f"${total_pagar:.2f}")
        messagebox.showinfo("Sucesso", f"Cálculo concluído para o cliente: {nombre}")
    except ValueError:
        messagebox.showerror("Error en los digitos", "Por favor, Solo introduzca numeros validos.")

ventana = tk.Tk()
ventana.title("Sistema de Vendas - Projeto")
ventana.geometry("450x550")
ventana.config(bg="#f4f4f4")
titulo = tk.Label(ventana, text="Cálculo de Compra e IVA", font=("Arial", 16, "bold"), bg="#f4f4f4", fg="#333")
titulo.pack(pady=15)
frame_cliente = tk.Frame(ventana, bg="#f4f4f4")
frame_cliente.pack(pady=5)

lbl_nombre = tk.Label(frame_cliente, text="Nombre del Cliente:", font=("Arial", 10, "bold"), bg="#f4f4f4")
lbl_nombre.pack(side=tk.LEFT, padx=5)

entrada_nombre = tk.Entry(frame_cliente, font=("Arial", 10), width=25)
entrada_nombre.pack(side=tk.LEFT, padx=5)

frame_precios = tk.LabelFrame(ventana, text=" Precios de los 5 Productos ", font=("Arial", 10, "bold"), bg="#f4f4f4", padx=15, pady=10)
frame_precios.pack(pady=15, fill="x", padx=20)

entradas_precios = []


for i in range(5):
    row_frame = tk.Frame(frame_precios, bg="#f4f4f4")
    row_frame.pack(pady=3, fill="x")
    
    lbl_prod = tk.Label(row_frame, text=f"Producto {i+1}:", font=("Arial", 10), bg="#f4f4f4", width=12, anchor="w")
    lbl_prod.pack(side=tk.LEFT)
    
    txt_entry = tk.Entry(row_frame, font=("Arial", 10))
    txt_entry.pack(side=tk.LEFT, expand=True, fill="x", padx=5)
    
    entradas_precios.append(txt_entry)

btn_calcular = tk.Button(ventana, text="Calcular Total e IVA", font=("Arial", 11, "bold"), bg="#4CAF50", fg="white", command=calcular_total, cursor="hand2", padx=10, pady=5)
btn_calcular.pack(pady=15)

frame_resultados = tk.LabelFrame(ventana, text=" Resumen de Cuenta ", font=("Arial", 10, "bold"), bg="#f4f4f4", padx=15, pady=10)
frame_resultados.pack(pady=10, fill="x", padx=20)

lbl_subtotal_tit = tk.Label(frame_resultados, text="Subtotal:", font=("Arial", 10), bg="#f4f4f4")
lbl_subtotal_tit.grid(row=0, column=0, sticky="w", pady=2)
lbl_subtotal_res = tk.Label(frame_resultados, text="$0.00", font=("Arial", 10, "bold"), bg="#f4f4f4")
lbl_subtotal_res.grid(row=0, column=1, sticky="e", padx=20)

lbl_iva_tit = tk.Label(frame_resultados, text="IVA (16%):", font=("Arial", 10), bg="#f4f4f4")
lbl_iva_tit.grid(row=1, column=0, sticky="w", pady=2)
lbl_iva_res = tk.Label(frame_resultados, text="$0.00", font=("Arial", 10, "bold"), bg="#f4f4f4", fg="#d32f2f")
lbl_iva_res.grid(row=1, column=1, sticky="e", padx=20)

lbl_total_tit = tk.Label(frame_resultados, text="TOTAL A PAGAR:", font=("Arial", 11, "bold"), bg="#f4f4f4")
lbl_total_tit.grid(row=2, column=0, sticky="w", pady=6)
lbl_total_res = tk.Label(frame_resultados, text="$0.00", font=("Arial", 11, "bold"), bg="#f4f4f4", fg="#1b5e20")
lbl_total_res.grid(row=2, column=1, sticky="e", padx=20)

frame_resultados.grid_columnconfigure(1, weight=1)

ventana.mainloop()