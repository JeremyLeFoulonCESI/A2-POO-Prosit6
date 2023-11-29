#pragma once

namespace HMI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ErrorMessage
	/// </summary>
	public ref class ErrorMessage : public System::Windows::Forms::Form
	{
	public:
		ErrorMessage(Exception^ err)
		{
			InitializeComponent(err);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ErrorMessage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ okButton;
	protected:

	private: System::Windows::Forms::Label^ errorMsg;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		void onOkButtonClicked(Object^ sender, EventArgs^ e) {
			this->Close();
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(Exception^ err)
		{
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->errorMsg = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(135, 107);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 0;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			// 
			// errorMsg
			// 
			this->errorMsg->AutoSize = true;
			this->errorMsg->MaximumSize = System::Drawing::Size(300, 0);
			this->errorMsg->Name = L"errorMsg";
			this->errorMsg->Size = System::Drawing::Size(107, 16);
			this->errorMsg->Text = err->ToString() + ": " + err->Message;
			this->errorMsg->Location = Point(
				(this->Width - this->errorMsg->Width) / 2,
				(this->Height - this->errorMsg->Height) / 2
			);
			this->errorMsg->TabIndex = 1;
			// 
			// ErrorMessage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(330, 147);
			this->Controls->Add(this->errorMsg);
			this->Controls->Add(this->okButton);
			this->Name = L"ErrorMessage";
			this->Text = L"Une erreur s\'est produite";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
