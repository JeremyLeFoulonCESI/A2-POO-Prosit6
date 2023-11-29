#pragma once

namespace HMI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddressSelector
	/// </summary>
	public ref class AddressSelector : public System::Windows::Forms::Form
	{
	public:
		AddressSelector(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void Reset() {
			this->InitializeComponent();
			this->canceled = true;
		}

		String^ getStreetNumber() {
			return this->streetNumberInput->Text;
		}
		String^ getStreet() {
			return this->streetInput->Text;
		}
		String^ getCity() {
			return this->cityInput->Text;
		}
		int getPostalCode() {
			return Convert::ToInt32(this->postalCodeInput);
		}

		System::Windows::Forms::DialogResult ShowDialog() override {
			this->Reset();
			auto res = this->Form::ShowDialog();
			if (this->canceled)
				return System::Windows::Forms::DialogResult::Cancel;
			return res;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddressSelector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ streetNumberInput;
	private: System::Windows::Forms::TextBox^ streetInput;
	private: System::Windows::Forms::TextBox^ cityInput;
	private: System::Windows::Forms::TextBox^ postalCodeInput;
	private: System::Windows::Forms::Button^ confirmButton;
	protected:





	private: System::Windows::Forms::Label^ streetNumberLabel;
	private: System::Windows::Forms::Label^ streetLabel;
	private: System::Windows::Forms::Label^ cityLabel;
	private: System::Windows::Forms::Label^ postalCodeLabel;
	private: System::Windows::Forms::Label^ streetNumberError;
	private: System::Windows::Forms::Label^ streetError;
	private: System::Windows::Forms::Label^ cityError;
	private: System::Windows::Forms::Label^ postalCodeError;
	private: System::Windows::Forms::Label^ postalCodeErrorInvalid;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		bool canceled;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->streetNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->streetInput = (gcnew System::Windows::Forms::TextBox());
			this->cityInput = (gcnew System::Windows::Forms::TextBox());
			this->postalCodeInput = (gcnew System::Windows::Forms::TextBox());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->streetNumberLabel = (gcnew System::Windows::Forms::Label());
			this->streetLabel = (gcnew System::Windows::Forms::Label());
			this->cityLabel = (gcnew System::Windows::Forms::Label());
			this->postalCodeLabel = (gcnew System::Windows::Forms::Label());
			this->streetNumberError = (gcnew System::Windows::Forms::Label());
			this->streetError = (gcnew System::Windows::Forms::Label());
			this->cityError = (gcnew System::Windows::Forms::Label());
			this->postalCodeError = (gcnew System::Windows::Forms::Label());
			this->postalCodeErrorInvalid = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// streetNumberInput
			// 
			this->streetNumberInput->ForeColor = System::Drawing::SystemColors::InfoText;
			this->streetNumberInput->Location = System::Drawing::Point(45, 57);
			this->streetNumberInput->Name = L"streetNumberInput";
			this->streetNumberInput->Size = System::Drawing::Size(203, 22);
			this->streetNumberInput->TabIndex = 0;
			// 
			// streetInput
			// 
			this->streetInput->ForeColor = System::Drawing::SystemColors::InfoText;
			this->streetInput->Location = System::Drawing::Point(45, 138);
			this->streetInput->Name = L"streetInput";
			this->streetInput->Size = System::Drawing::Size(203, 22);
			this->streetInput->TabIndex = 1;
			// 
			// cityInput
			// 
			this->cityInput->ForeColor = System::Drawing::SystemColors::InfoText;
			this->cityInput->Location = System::Drawing::Point(45, 223);
			this->cityInput->Name = L"cityInput";
			this->cityInput->Size = System::Drawing::Size(203, 22);
			this->cityInput->TabIndex = 2;
			// 
			// postalCodeInput
			// 
			this->postalCodeInput->Location = System::Drawing::Point(45, 309);
			this->postalCodeInput->Name = L"postalCodeInput";
			this->postalCodeInput->Size = System::Drawing::Size(203, 22);
			this->postalCodeInput->TabIndex = 3;
			this->postalCodeInput->TextChanged += gcnew System::EventHandler(this, &AddressSelector::textBox4_TextChanged);
			// 
			// confirmButton
			// 
			this->confirmButton->Location = System::Drawing::Point(103, 368);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(75, 23);
			this->confirmButton->TabIndex = 4;
			this->confirmButton->Text = L"Valider";
			this->confirmButton->UseVisualStyleBackColor = true;
			this->confirmButton->Click += gcnew EventHandler(this, &AddressSelector::okButton_Click);
			// 
			// streetNumberLabel
			// 
			this->streetNumberLabel->AutoSize = true;
			this->streetNumberLabel->Location = System::Drawing::Point(42, 38);
			this->streetNumberLabel->Name = L"streetNumberLabel";
			this->streetNumberLabel->Size = System::Drawing::Size(96, 16);
			this->streetNumberLabel->TabIndex = 5;
			this->streetNumberLabel->Text = L"Numéro de rue";
			// 
			// streetLabel
			// 
			this->streetLabel->AutoSize = true;
			this->streetLabel->Location = System::Drawing::Point(42, 119);
			this->streetLabel->Name = L"streetLabel";
			this->streetLabel->Size = System::Drawing::Size(77, 16);
			this->streetLabel->TabIndex = 6;
			this->streetLabel->Text = L"Nom de rue";
			// 
			// cityLabel
			// 
			this->cityLabel->AutoSize = true;
			this->cityLabel->Location = System::Drawing::Point(42, 204);
			this->cityLabel->Name = L"cityLabel";
			this->cityLabel->Size = System::Drawing::Size(33, 16);
			this->cityLabel->TabIndex = 7;
			this->cityLabel->Text = L"Ville";
			// 
			// postalCodeLabel
			// 
			this->postalCodeLabel->AutoSize = true;
			this->postalCodeLabel->Location = System::Drawing::Point(42, 290);
			this->postalCodeLabel->Name = L"postalCodeLabel";
			this->postalCodeLabel->Size = System::Drawing::Size(80, 16);
			this->postalCodeLabel->TabIndex = 8;
			this->postalCodeLabel->Text = L"Code postal";
			// 
			// streetNumberError
			// 
			this->streetNumberError->AutoSize = true;
			this->streetNumberError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->streetNumberError->ForeColor = System::Drawing::Color::Red;
			this->streetNumberError->Location = System::Drawing::Point(42, 82);
			this->streetNumberError->Name = L"streetNumberError";
			this->streetNumberError->Size = System::Drawing::Size(181, 13);
			this->streetNumberError->TabIndex = 18;
			this->streetNumberError->Text = L"Veuillez renseigner un numéro de rue";
			this->streetNumberError->Visible = false;
			// 
			// streetError
			// 
			this->streetError->AutoSize = true;
			this->streetError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->streetError->ForeColor = System::Drawing::Color::Red;
			this->streetError->Location = System::Drawing::Point(42, 163);
			this->streetError->Name = L"streetError";
			this->streetError->Size = System::Drawing::Size(166, 13);
			this->streetError->TabIndex = 19;
			this->streetError->Text = L"Veuillez renseigner un nom de rue";
			this->streetError->Visible = false;
			// 
			// cityError
			// 
			this->cityError->AutoSize = true;
			this->cityError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->cityError->ForeColor = System::Drawing::Color::Red;
			this->cityError->Location = System::Drawing::Point(42, 248);
			this->cityError->Name = L"cityError";
			this->cityError->Size = System::Drawing::Size(169, 13);
			this->cityError->TabIndex = 20;
			this->cityError->Text = L"Veuillez renseigner un nom de ville";
			this->cityError->Visible = false;
			// 
			// postalCodeError
			// 
			this->postalCodeError->AutoSize = true;
			this->postalCodeError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->postalCodeError->ForeColor = System::Drawing::Color::Red;
			this->postalCodeError->Location = System::Drawing::Point(42, 334);
			this->postalCodeError->Name = L"postalCodeError";
			this->postalCodeError->Size = System::Drawing::Size(167, 13);
			this->postalCodeError->TabIndex = 21;
			this->postalCodeError->Text = L"Veuillez renseigner un code postal";
			this->postalCodeError->Visible = false;
			// 
			// postalCodeErrorInvalid
			// 
			this->postalCodeErrorInvalid->AutoSize = true;
			this->postalCodeErrorInvalid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->postalCodeErrorInvalid->ForeColor = System::Drawing::Color::Red;
			this->postalCodeErrorInvalid->Location = System::Drawing::Point(42, 334);
			this->postalCodeErrorInvalid->Name = L"postalCodeErrorInvalid";
			this->postalCodeErrorInvalid->Size = System::Drawing::Size(199, 13);
			this->postalCodeErrorInvalid->TabIndex = 22;
			this->postalCodeErrorInvalid->Text = L"Le code postal doit être un nombre entier";
			this->postalCodeErrorInvalid->Visible = false;
			// 
			// AddressSelector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 403);
			this->Controls->Add(this->postalCodeErrorInvalid);
			this->Controls->Add(this->postalCodeError);
			this->Controls->Add(this->cityError);
			this->Controls->Add(this->streetError);
			this->Controls->Add(this->streetNumberError);
			this->Controls->Add(this->postalCodeLabel);
			this->Controls->Add(this->cityLabel);
			this->Controls->Add(this->streetLabel);
			this->Controls->Add(this->streetNumberLabel);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->postalCodeInput);
			this->Controls->Add(this->cityInput);
			this->Controls->Add(this->streetInput);
			this->Controls->Add(this->streetNumberInput);
			this->Name = L"AddressSelector";
			this->Text = L"Editeur d\'adresses";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		void okButton_Click(Object^ sender, EventArgs^ e) {
			bool valid = true;
			if (this->streetInput->Text->Length == 0) {
				valid = false;
				this->streetError->Visible = true;
			}
			if (this->streetNumberInput->Text->Length == 0) {
				valid = false;
				this->streetNumberError->Visible = true;
			}
			if (this->cityInput->Text->Length == 0) {
				valid = false;
				this->cityError->Visible = true;
			}
			if (!Int32::Parse(this->postalCodeInput->Text)) {
				valid = false;
				this->postalCodeErrorInvalid->Visible = true;
			}
			if (this->postalCodeInput->Text->Length == 0) {
				valid = false;
				this->postalCodeError->Visible = true;
			}

			if (!valid)
				return;
			this->Close();
		}
};
}
