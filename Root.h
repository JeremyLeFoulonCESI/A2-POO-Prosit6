#pragma once
#include "AddressSelector.h"

namespace HMI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Root
	/// </summary>
	public ref class Root : public System::Windows::Forms::Form
	{
	public:
		Root(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Root()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ viewGrid;
	protected:

	private: System::Windows::Forms::Button^ clientEditorConfirm;

	private: System::Windows::Forms::Label^ clientEditorTitle;
	private: System::Windows::Forms::TextBox^ firstNameInput;
	private: System::Windows::Forms::TextBox^ lastNameInput;
	private: System::Windows::Forms::TextBox^ deliveryDisplay;
	private: System::Windows::Forms::TextBox^ facturingDisplay;
	private: System::Windows::Forms::Button^ deliveryButton;
	private: System::Windows::Forms::Button^ facturingButton;








	private: System::Windows::Forms::Label^ firstNameLabel;
	private: System::Windows::Forms::Label^ lastNameLabel;
	private: System::Windows::Forms::Label^ deliveryLabel;
	private: System::Windows::Forms::Label^ facturingLabel;

	private: System::Windows::Forms::Button^ viewDelete;
	private: System::Windows::Forms::RadioButton^ addClientSelector;
	private: System::Windows::Forms::RadioButton^ editClientSelector;
	private: System::Windows::Forms::Label^ firstNameError;
	private: System::Windows::Forms::Label^ lastNameError;
	private: System::Windows::Forms::Label^ deliveryError;
	private: System::Windows::Forms::Label^ facturationError;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		AddressSelector^ selector;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->selector = gcnew AddressSelector();

			this->viewGrid = (gcnew System::Windows::Forms::DataGridView());
			this->clientEditorConfirm = (gcnew System::Windows::Forms::Button());
			this->clientEditorTitle = (gcnew System::Windows::Forms::Label());
			this->firstNameInput = (gcnew System::Windows::Forms::TextBox());
			this->lastNameInput = (gcnew System::Windows::Forms::TextBox());
			this->deliveryDisplay = (gcnew System::Windows::Forms::TextBox());
			this->facturingDisplay = (gcnew System::Windows::Forms::TextBox());
			this->deliveryButton = (gcnew System::Windows::Forms::Button());
			this->facturingButton = (gcnew System::Windows::Forms::Button());
			this->firstNameLabel = (gcnew System::Windows::Forms::Label());
			this->lastNameLabel = (gcnew System::Windows::Forms::Label());
			this->deliveryLabel = (gcnew System::Windows::Forms::Label());
			this->facturingLabel = (gcnew System::Windows::Forms::Label());
			this->viewDelete = (gcnew System::Windows::Forms::Button());
			this->addClientSelector = (gcnew System::Windows::Forms::RadioButton());
			this->editClientSelector = (gcnew System::Windows::Forms::RadioButton());
			this->firstNameError = (gcnew System::Windows::Forms::Label());
			this->lastNameError = (gcnew System::Windows::Forms::Label());
			this->deliveryError = (gcnew System::Windows::Forms::Label());
			this->facturationError = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->viewGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// viewGrid
			// 
			this->viewGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->viewGrid->Location = System::Drawing::Point(399, 12);
			this->viewGrid->Name = L"viewGrid";
			this->viewGrid->RowHeadersWidth = 51;
			this->viewGrid->RowTemplate->Height = 24;
			this->viewGrid->Size = System::Drawing::Size(370, 332);
			this->viewGrid->TabIndex = 0;
			// 
			// clientEditorConfirm
			// 
			this->clientEditorConfirm->Location = System::Drawing::Point(41, 357);
			this->clientEditorConfirm->Name = L"clientEditorConfirm";
			this->clientEditorConfirm->Size = System::Drawing::Size(137, 33);
			this->clientEditorConfirm->TabIndex = 1;
			this->clientEditorConfirm->Text = L"Valider";
			this->clientEditorConfirm->UseVisualStyleBackColor = true;
			// 
			// clientEditorTitle
			// 
			this->clientEditorTitle->AutoSize = true;
			this->clientEditorTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->clientEditorTitle->Location = System::Drawing::Point(116, 12);
			this->clientEditorTitle->Name = L"clientEditorTitle";
			this->clientEditorTitle->Size = System::Drawing::Size(146, 25);
			this->clientEditorTitle->TabIndex = 2;
			this->clientEditorTitle->Text = L"Nouveau Client";
			// 
			// firstNameInput
			// 
			this->firstNameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F));
			this->firstNameInput->Location = System::Drawing::Point(41, 74);
			this->firstNameInput->Name = L"firstNameInput";
			this->firstNameInput->Size = System::Drawing::Size(303, 24);
			this->firstNameInput->TabIndex = 3;
			// 
			// lastNameInput
			// 
			this->lastNameInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F));
			this->lastNameInput->Location = System::Drawing::Point(41, 148);
			this->lastNameInput->Name = L"lastNameInput";
			this->lastNameInput->Size = System::Drawing::Size(303, 24);
			this->lastNameInput->TabIndex = 4;
			// 
			// deliveryDisplay
			// 
			this->deliveryDisplay->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->deliveryDisplay->Enabled = false;
			this->deliveryDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F));
			this->deliveryDisplay->Location = System::Drawing::Point(41, 226);
			this->deliveryDisplay->Name = L"deliveryDisplay";
			this->deliveryDisplay->Size = System::Drawing::Size(269, 24);
			this->deliveryDisplay->TabIndex = 5;
			// 
			// facturingDisplay
			// 
			this->facturingDisplay->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->facturingDisplay->Enabled = false;
			this->facturingDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F));
			this->facturingDisplay->Location = System::Drawing::Point(41, 302);
			this->facturingDisplay->Name = L"facturingDisplay";
			this->facturingDisplay->Size = System::Drawing::Size(269, 24);
			this->facturingDisplay->TabIndex = 6;
			// 
			// deliveryButton
			// 
			this->deliveryButton->Location = System::Drawing::Point(308, 226);
			this->deliveryButton->Name = L"deliveryButton";
			this->deliveryButton->Size = System::Drawing::Size(36, 24);
			this->deliveryButton->TabIndex = 7;
			this->deliveryButton->Text = L"...";
			this->deliveryButton->UseVisualStyleBackColor = true;
			// 
			// facturingButton
			// 
			this->facturingButton->Location = System::Drawing::Point(308, 302);
			this->facturingButton->Name = L"facturingButton";
			this->facturingButton->Size = System::Drawing::Size(36, 24);
			this->facturingButton->TabIndex = 8;
			this->facturingButton->Text = L"...";
			this->facturingButton->UseVisualStyleBackColor = true;
			// 
			// firstNameLabel
			// 
			this->firstNameLabel->AutoSize = true;
			this->firstNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->firstNameLabel->Location = System::Drawing::Point(38, 53);
			this->firstNameLabel->Name = L"firstNameLabel";
			this->firstNameLabel->Size = System::Drawing::Size(61, 18);
			this->firstNameLabel->TabIndex = 9;
			this->firstNameLabel->Text = L"Prénom";
			// 
			// lastNameLabel
			// 
			this->lastNameLabel->AutoSize = true;
			this->lastNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lastNameLabel->Location = System::Drawing::Point(38, 127);
			this->lastNameLabel->Name = L"lastNameLabel";
			this->lastNameLabel->Size = System::Drawing::Size(41, 18);
			this->lastNameLabel->TabIndex = 10;
			this->lastNameLabel->Text = L"Nom";
			// 
			// deliveryLabel
			// 
			this->deliveryLabel->AutoSize = true;
			this->deliveryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->deliveryLabel->Location = System::Drawing::Point(38, 205);
			this->deliveryLabel->Name = L"deliveryLabel";
			this->deliveryLabel->Size = System::Drawing::Size(140, 18);
			this->deliveryLabel->TabIndex = 11;
			this->deliveryLabel->Text = L"Adresse de livraison";
			// 
			// facturingLabel
			// 
			this->facturingLabel->AutoSize = true;
			this->facturingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->facturingLabel->Location = System::Drawing::Point(38, 281);
			this->facturingLabel->Name = L"facturingLabel";
			this->facturingLabel->Size = System::Drawing::Size(155, 18);
			this->facturingLabel->TabIndex = 12;
			this->facturingLabel->Text = L"Adresse de facturation";
			// 
			// viewDelete
			// 
			this->viewDelete->Location = System::Drawing::Point(484, 367);
			this->viewDelete->Name = L"viewDelete";
			this->viewDelete->Size = System::Drawing::Size(184, 23);
			this->viewDelete->TabIndex = 14;
			this->viewDelete->Text = L"Supprimer";
			this->viewDelete->UseVisualStyleBackColor = true;
			// 
			// addClientSelector
			// 
			this->addClientSelector->AutoSize = true;
			this->addClientSelector->Checked = true;
			this->addClientSelector->Location = System::Drawing::Point(193, 367);
			this->addClientSelector->Name = L"addClientSelector";
			this->addClientSelector->Size = System::Drawing::Size(69, 20);
			this->addClientSelector->TabIndex = 15;
			this->addClientSelector->TabStop = true;
			this->addClientSelector->Text = L"ajouter";
			this->addClientSelector->UseVisualStyleBackColor = true;
			// 
			// editClientSelector
			// 
			this->editClientSelector->AutoSize = true;
			this->editClientSelector->Location = System::Drawing::Point(268, 367);
			this->editClientSelector->Name = L"editClientSelector";
			this->editClientSelector->Size = System::Drawing::Size(76, 20);
			this->editClientSelector->TabIndex = 16;
			this->editClientSelector->TabStop = true;
			this->editClientSelector->Text = L"modifier";
			this->editClientSelector->UseVisualStyleBackColor = true;
			// 
			// firstNameError
			// 
			this->firstNameError->AutoSize = true;
			this->firstNameError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->firstNameError->ForeColor = System::Drawing::Color::Red;
			this->firstNameError->Location = System::Drawing::Point(38, 101);
			this->firstNameError->Name = L"firstNameError";
			this->firstNameError->Size = System::Drawing::Size(148, 13);
			this->firstNameError->TabIndex = 17;
			this->firstNameError->Text = L"Veuillez renseigner un prénom";
			this->firstNameError->Visible = false;
			// 
			// lastNameError
			// 
			this->lastNameError->AutoSize = true;
			this->lastNameError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->lastNameError->ForeColor = System::Drawing::Color::Red;
			this->lastNameError->Location = System::Drawing::Point(38, 175);
			this->lastNameError->Name = L"lastNameError";
			this->lastNameError->Size = System::Drawing::Size(133, 13);
			this->lastNameError->TabIndex = 18;
			this->lastNameError->Text = L"Veuillez renseigner un nom";
			this->lastNameError->Visible = false;
			// 
			// deliveryError
			// 
			this->deliveryError->AutoSize = true;
			this->deliveryError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->deliveryError->ForeColor = System::Drawing::Color::Red;
			this->deliveryError->Location = System::Drawing::Point(38, 253);
			this->deliveryError->Name = L"deliveryError";
			this->deliveryError->Size = System::Drawing::Size(212, 13);
			this->deliveryError->TabIndex = 19;
			this->deliveryError->Text = L"Veuillez renseigner une adresse de livraison";
			this->deliveryError->Visible = false;
			// 
			// facturationError
			// 
			this->facturationError->AutoSize = true;
			this->facturationError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->facturationError->ForeColor = System::Drawing::Color::Red;
			this->facturationError->Location = System::Drawing::Point(38, 329);
			this->facturationError->Name = L"facturationError";
			this->facturationError->Size = System::Drawing::Size(223, 13);
			this->facturationError->TabIndex = 20;
			this->facturationError->Text = L"Veuillez renseigner une adresse de facturation";
			this->facturationError->Visible = false;
			// 
			// Root
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(799, 407);
			this->Controls->Add(this->facturationError);
			this->Controls->Add(this->deliveryError);
			this->Controls->Add(this->lastNameError);
			this->Controls->Add(this->firstNameError);
			this->Controls->Add(this->editClientSelector);
			this->Controls->Add(this->addClientSelector);
			this->Controls->Add(this->viewDelete);
			this->Controls->Add(this->facturingLabel);
			this->Controls->Add(this->deliveryLabel);
			this->Controls->Add(this->lastNameLabel);
			this->Controls->Add(this->firstNameLabel);
			this->Controls->Add(this->facturingButton);
			this->Controls->Add(this->deliveryButton);
			this->Controls->Add(this->facturingDisplay);
			this->Controls->Add(this->deliveryDisplay);
			this->Controls->Add(this->lastNameInput);
			this->Controls->Add(this->firstNameInput);
			this->Controls->Add(this->clientEditorTitle);
			this->Controls->Add(this->clientEditorConfirm);
			this->Controls->Add(this->viewGrid);
			this->Name = L"Root";
			this->Text = L"Delivery Manager";
			this->Load += gcnew System::EventHandler(this, &Root::Root_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->viewGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void Root_Load(Object^ sender, EventArgs^ e) {
		}
		void deliveryButton_Click(Object^ sender, EventArgs^ e) {
			
		}

	};
}
